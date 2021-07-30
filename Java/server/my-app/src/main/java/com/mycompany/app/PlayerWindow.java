package com.mycompany.app;

import com.mycompany.app.App;

public class PlayerWindow extends PlayersObserver{
    App app;

    public PlayerWindow(App app){
       this.app = app;
       this.app.attach(this);
    }
 
    @Override
    public void update() {
//       System.out.println( "Binary String: " + Integer.toBinaryString( subject.getState() ) ); 
        System.out.println("PlayersWindow update");

        PlayersOuterClass.Players players = app.getPlayers();

        System.out.println("PlayerWindow Players size:" + players.getPlayerListCount());
        for (int i = 0; i < players.getPlayerListCount(); i++)
        {
            PlayersOuterClass.Player player = players.getPlayerList(i);
            System.out.println(player.toString());
        }

    }
 }