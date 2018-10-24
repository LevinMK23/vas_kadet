import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, Integer> map = new HashMap<>();
        while(true){
            String [] line = in.readLine().split(" ");
            //System.out.println(Arrays.toString(line));
            if(line[0].equals("")) continue;
            if(line[0].equals("QUERIES")){
                while (true){
                    String query = in.readLine();
                    if(query == null) return;
                    System.out.println(map.getOrDefault(query, 0));
                }
            }
            else  {
                StringBuilder name = new StringBuilder();
                for (int i = 0; i < line.length - 1; i++) {
                    name.append(line[i]).append(" ");
                }
                name.deleteCharAt(name.length()-1);
                String n = name.toString();
                if (map.containsKey(n)) {
                    map.put(n, map.get(n) + Integer.parseInt(line[line.length - 1]));
                } else {
                    map.put(n, Integer.parseInt(line[line.length - 1]));
                }
            }
        }
    }
}
