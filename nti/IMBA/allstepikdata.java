import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        File dir = new File("/home/stepic/instances/master-plugins/arena/");
        File [] files = dir.listFiles();
        for (File f : files) {
            File [] indir = f.listFiles();
            for(File i : indir){
                if(i.isFile()) {
                    Scanner in = new Scanner(i);
                    while (in.hasNextLine()) System.out.println(in.nextLine());
                }
            }

            System.out.println(f.getAbsolutePath());
        }
    }

}
