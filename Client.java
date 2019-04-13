package module5;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {

    private Socket socket;
    private InputStream in;
    private OutputStream out;

    public Client() {
        try {
            socket = new Socket("127.0.0.1", 8080);
            in = socket.getInputStream();
            out = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(out);
            writer.println("msg from client - ");
            writer.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Client();
    }
}
