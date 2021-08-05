#include <iostream>
#include "Players.pb.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <thread>

#define SERVERNAME "/tmp/PlayersServer"
#define CLIENTNAME "/tmp/PlayersClient"

using namespace std;

void listenForServerMsgs()
{
    int sock, msgsock, rval;
    struct sockaddr_un server;
    char buf[1024];

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }
    else
    {
        cout << "listenForServerMsgs socket created" << endl;
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, CLIENTNAME);
    if (::bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un))) {
        perror("binding stream socket");
        exit(1);
    }
    printf("Socket has name %s\n", server.sun_path);
    listen(sock, 30);
    cout << "listenForServerMsgs listen returned" << endl;
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
                printf("-->%s\n", buf);
        } while (rval > 0);
        close(msgsock);
    }
    close(sock);
    unlink(CLIENTNAME);
}

int main()
{
    cout << "main started" << endl;
    ::test::Players *players = new test::Players;

    test::Player* player = players->add_playerlist();

    if (player)
    {
        player->set_playerid(1);
        player->set_playername("Jalen Hurts");
        player->set_playernumber(2);
        player->set_playerposition("Quarterback");

        cout << "Player: " << player->DebugString() << endl;
    }

    player = players->add_playerlist();

    if (player)
    {
        player->set_playerid(2);
        player->set_playername("Devonta Smith");
        player->set_playernumber(6);
        player->set_playerposition("Wide Receiver");

        cout << "Player: " << player->DebugString() << endl;
    }

    int sock;
    struct sockaddr_un server;
    //char buf[1024];
    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, SERVERNAME);

    if (connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un)) < 0) 
    {
        close(sock);
        perror("connecting stream socket");
        exit(1);
    }

    cout << "Listening for server msgs" << endl;

    std::thread t1(listenForServerMsgs);

    usleep(1000000);

    int count = 1;

    for(;;)
    {
        if (10 == count)
        {
            player = players->add_playerlist();

            if (player)
            {
                player->set_playerid(3);
                player->set_playername("Zach Ertz");
                player->set_playernumber(86);
                player->set_playerposition("Tight End");

                cout << "Player: " << player->DebugString() << endl;
            }
        }
        if (20 == count) 
        {
            player = players->add_playerlist();

            if (player)
            {
                player->set_playerid(4);
                player->set_playername("Jalen Raegor");
                player->set_playernumber(18);
                player->set_playerposition("Wide Receiver");

                cout << "Player: " << player->DebugString() << endl;
            }
        }
        if (30 == count) 
        {
            player = players->add_playerlist();

            if (player)
            {
                player->set_playerid(5);
                player->set_playername("Flectcher Cox");
                player->set_playernumber(91);
                player->set_playerposition("Defensive Tackle");

                cout << "Player: " << player->DebugString() << endl;
            }
        }

        int size = players->ByteSizeLong();

        cout << "players size: " << size << endl;

        char* array = new char[size];

        players->SerializeToArray(array, size);

        std::string outData = players->SerializeAsString();

        if (write(sock, array, size) < 0)
        {
            perror("writing on stream socket");
        }
        usleep(1000000);
 
        count++;
    }
    close(sock);
}