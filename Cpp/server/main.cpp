#include "Players.pb.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <thread>

using namespace std;

#define SERVERNAME "/tmp/PlayersServer"
#define CLIENTNAME "/tmp/PlayersClient"

auto readyToSend = false;

void sendClientMsgs()
{
    while(false == readyToSend)
    {
        usleep(1000000);
    }

    int sock;

    struct sockaddr_un server;

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, CLIENTNAME);

    if (connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un)) < 0) 
    {
        close(sock);
        perror("connecting stream socket");
        exit(1);
    }

    int msgCount = 0;

    for(;;)
    {
        msgCount++;
        char buf[1024];

        strcpy(buf,"Server message: ");
        string s = std::to_string(msgCount);
        strcat(buf,s.c_str());
        if (write(sock, buf, sizeof(buf)) < 0)
        {
            perror("writing on stream socket");
        }
        usleep(1000000);
    }
    close(sock);
}

int main()
{
    int sock, msgsock, rval;
    struct sockaddr_un server;
    char buf[1024];


    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SERVERNAME);
    if (::bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un))) {
        perror("binding stream socket");
        exit(1);
    }
    printf("Socket has name %s\n", server.sun_path);

    listen(sock, 5);

    cout << "Creating sender thread" << endl;

    std::thread t1(sendClientMsgs);

    for (;;) {
        msgsock = accept(sock, 0, 0);
        if (msgsock == -1)
            perror("accept");
        else do {
            bzero(buf, sizeof(buf));
            if ((rval = read(msgsock, buf, 1024)) < 0)
                perror("reading stream message");
            else if (rval == 0)
                printf("Ending connection\n");
            else
                if (false == readyToSend)
                {
                    readyToSend = true;
                }
                //printf("-->%s\n", buf);
                test::Players players;
                players.ParseFromArray(buf,rval);
                int numPlayers = players.playerlist_size();
                cout << "Number of players: " << numPlayers << endl;
                for (int i = 0; i < numPlayers; i++)
                {
                    test::Player player = players.playerlist(i);
                    cout << player.DebugString() << endl;
                }
                cout << "********************" << endl;

        } while (rval > 0);
        close(msgsock);
    }
    close(sock);
    unlink(SERVERNAME);
}

