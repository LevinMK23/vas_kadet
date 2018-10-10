import java.util.TreeMap;

public class School {

    String name;
    TreeMap<String, Class> classes;

    public School(String name) {
        this.name = name;
        classes = new TreeMap<>();
    }
}
