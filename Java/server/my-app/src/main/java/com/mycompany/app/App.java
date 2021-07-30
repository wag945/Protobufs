package com.mycompany.app;

import java.io.IOException;
import java.net.StandardProtocolFamily;
import java.net.UnixDomainSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Optional;
import java.util.ArrayList;
import java.util.List;

//import com.mycompany.app.PlayersOuterClass.Players;
//import PlayersOuterClass.Players;

import com.mycompany.app.PlayersOuterClass.Players;

public class App 
{
    private List<PlayersObserver> observers = new ArrayList<PlayersObserver>();

    PlayersOuterClass.Players myPlayers;

    private void readAndPrintMessages(SocketChannel channel) throws IOException, InterruptedException
    {
        while(true)
        {
            readMessageFromSocket(channel);
            Thread.sleep(100);
        }
    }

//    private static Optional<String> readMessageFromSocket(SocketChannel channel) throws IOException
    private void readMessageFromSocket(SocketChannel channel) throws IOException
    {
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        int bytesRead = channel.read(buffer);
        System.out.println("bytesRead: " + bytesRead);
        if (bytesRead < 0)
        {
            System.out.println("returning because bytesRead < 0");
//            return Optional.empty();
            return;
        }
        System.out.println("after bytesRead < 0 check");
        byte[] bytes = new byte[bytesRead];
        buffer.flip();
        buffer.get(bytes);
        String message = new String(bytes);
        System.out.println("About to call parseFrom");
        PlayersOuterClass.Players players = Players.parseFrom(bytes);
        myPlayers = players;
        System.out.println("Players size:" + players.getPlayerListCount());
        for (int i = 0; i < players.getPlayerListCount(); i++)
        {
            PlayersOuterClass.Player player = players.getPlayerList(i);
            System.out.println(player.toString());
        }

        notifyAllObservers();
//        return Optional.of(message);
    }

    public void attach(PlayersObserver observer){
        observers.add(observer);		
     }
  
     public void notifyAllObservers(){
        for (PlayersObserver observer : observers) {
           observer.update();
        }
     }
     
     public PlayersOuterClass.Players getPlayers()
     {
         return this.myPlayers;
     }

    public static void main(String[] args)
        throws IOException, InterruptedException
    {
        App app = new App();

        PlayerWindow playerWindow = new PlayerWindow(app);

        Path socketFile = Path.of("/tmp").resolve("PlayersServer");
        //Files.deleteIfExists(socketFile);
        
        UnixDomainSocketAddress address = UnixDomainSocketAddress.of(socketFile);

        ServerSocketChannel serverChannel = ServerSocketChannel.open(StandardProtocolFamily.UNIX);
        serverChannel.bind(address);

        System.out.println("[INFO] Waiting for client to connect...");
        SocketChannel channel = serverChannel.accept();
        System.out.println("[INFO] Client connected");

        app.readAndPrintMessages(channel);
    }
}
