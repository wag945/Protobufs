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
//import com.mycompany.app.PlayersOuterClass.Players;
//import PlayersOuterClass.Players;

import com.mycompany.app.PlayersOuterClass.Players;

public class App 
{
    private static void readAndPrintMessages(SocketChannel channel) throws IOException, InterruptedException
    {
        while(true)
        {
            readMessageFromSocket(channel).ifPresent(System.out::println);
            Thread.sleep(100);
        }
    }

    private static Optional<String> readMessageFromSocket(SocketChannel channel) throws IOException
    {
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        int bytesRead = channel.read(buffer);
        System.out.println("bytesRead: " + bytesRead);
        if (bytesRead < 0)
        {
            return Optional.empty();
        }
        byte[] bytes = new byte[bytesRead];
        buffer.flip();
        buffer.get(bytes);
        String message = new String(bytes);
        PlayersOuterClass.Players players = Players.parseFrom(bytes);
        PlayersOuterClass.Player player = players.getPlayerList(0);
        System.out.println(player.toString());
        return Optional.of(message);
    }

    public static void main(String[] args)
        throws IOException, InterruptedException
    {
        Path socketFile = Path.of("/tmp").resolve("PlayersServer");
        //Files.deleteIfExists(socketFile);
        
        UnixDomainSocketAddress address = UnixDomainSocketAddress.of(socketFile);

        ServerSocketChannel serverChannel = ServerSocketChannel.open(StandardProtocolFamily.UNIX);
        serverChannel.bind(address);

        System.out.println("[INFO] Waiting for client to connect...");
        SocketChannel channel = serverChannel.accept();
        System.out.println("[INFO] Client connected");

        readAndPrintMessages(channel);
    }
}
