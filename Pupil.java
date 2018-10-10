import java.util.ArrayList;

public class Pupil {
    String name, sername, fathername;
    ArrayList<Integer> marks;
    int c2, c5, sum;
    double avg;
    void calc(){
        c2 = 0; c5 = 0; sum = 0;
        for(Integer mark : marks){
            sum += mark;
            c2 += mark == 2 ? 1 : 0;
            c5 += mark == 5 ? 1 : 0;
        }
        avg = (double) sum / marks.size();
    }

    @Override
    public String toString() {
        calc();
        return sername + " "
                + name.charAt(0) + ". "
                + fathername.charAt(0) + ". " + String.format("%.3f", avg);
    }

    public Pupil(String sername, String name, String fathername) {
        this.name = name;
        this.sername = sername;
        this.fathername = fathername;
        marks = new ArrayList<>();
    }
}
