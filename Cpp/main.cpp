#include <iostream>
#include "Players.pb.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define NAME "/tmp/socket"
using namespace std;

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

    #define DATA "Half a league, half a league . . ."
    int sock;
    struct sockaddr_un server;
    //char buf[1024];
    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("opening stream socket");
        exit(1);
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, NAME);

    if (connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un)) < 0) 
    {
        close(sock);
        perror("connecting stream socket");
        exit(1);
    }

    time_t rawtime;
    struct tm * timeinfo;

    for(;;)
    {
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        char buf[1024];
        strcpy(buf,asctime(timeinfo));
        printf ( "The current date/time is: %s", buf );
        if (write(sock, buf, sizeof(buf)) < 0)
        {
            perror("writing on stream socket");
        }
        usleep(1000000);
    }
    close(sock);
}