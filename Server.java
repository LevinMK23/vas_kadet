package module5;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
    private static int cnt = 1;
    private ServerSocket srv;
    private Socket socket;
    private InputStream in;
    private OutputStream out;

    public Server() {
        try {
            srv = new ServerSocket(8080);
            while (true) {
                socket = srv.accept();
                System.out.println("Client connected with ip:" + socket.getInetAddress());
                Scanner input = new Scanner(socket
                        .getInputStream());
                System.out.println(input.nextLine() + cnt++);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Server();
    }
}
