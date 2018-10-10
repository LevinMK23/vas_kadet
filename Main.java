import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("/home/acid/IdeaProjects/Geekbrains/src/Olimp/sort/sort1/StructSort/data.txt"));
        TreeMap<String, School> schools = new TreeMap<>();
        while (in.hasNextLine()){
            String [] l = in.nextLine().split(" ");
            Pupil pupil = new Pupil(l[0], l[1], l[2]);
            for (int i = 5; i < l.length; i++){
                pupil.marks.add(Integer.parseInt(l[i]));
            }
            pupil.calc();
            if (schools.containsKey(l[3])){
                if (schools.get(l[3]).classes.containsKey(l[4])){
                    schools.get(l[3]).classes.get(l[4]).pupils.add(pupil);
                }
                else{
                    schools.get(l[3]).classes.put(l[4], new Class(l[4]));
                    schools.get(l[3]).classes.get(l[4]).pupils.add(pupil);
                }
            }
            else{
                schools.put(l[3], new School(l[3]));
                schools.get(l[3]).classes.put(l[4], new Class(l[4]));
                schools.get(l[3]).classes.get(l[4]).pupils.add(pupil);
            }
        }
        System.out.println("Отчет по среднему баллу:");
        for (Map.Entry<String, School> entry : schools.entrySet()){
            System.out.println("Школа №" + entry.getKey() + ":");
            for (Map.Entry<String, Class> cl : entry.getValue().classes.entrySet()){
                System.out.println(cl.getKey() + " класс:");
                Collections.sort(cl.getValue().pupils, Comparator.comparingDouble(pupil -> -pupil.avg));
                for (Pupil pupil : cl.getValue().pupils){
                    System.out.println(pupil);
                }
            }
        }
    }
}
