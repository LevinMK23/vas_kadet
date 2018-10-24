import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long n = new Scanner(System.in).nextLong();
        String s = Long.toBinaryString(n);
        while (s.length() < 32) s = "0" + s;
        //System.out.println(s);
        ArrayList<String> base = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        int c= 0;
        for (int i = s.length()-1; i >= 0; i--) {
            sb.insert(0, s.charAt(i));
            c++;
            if(c % 8 == 0) {
                base.add(0, sb.toString());
                c = 0;
                sb = new StringBuilder();
            }
        }
        //System.out.println(base);
        long ans = 0, r = 1;
        for (int i = 0; i < base.size(); i++) {
            ans += r * convertToDec(base.get(i));
            r *= 256;
        }
        System.out.println(ans);
    }

    private static long convertToDec(String s) {
        int ans = 0, r = 1;
        for (int i = s.length()-1; i >= 0 ; i--) {
            ans += (s.charAt(i) - '0') * r;
            r *= 2;
        }
        return ans;
    }
}
