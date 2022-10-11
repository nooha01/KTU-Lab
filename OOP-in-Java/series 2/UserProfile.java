import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.File;
import java.util.*;

public class UserProfile {
    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the number of users:");
            int n = sc.nextInt();
            FileWriter fw1 = new FileWriter("valid.txt");
            FileWriter fw2 = new FileWriter("invaid.txt");

            String u;
            int ps;
            String p;

            while (n > 0) {
                System.out.println("UserName :");
                u = sc.next();
                System.out.println("Password :");
                p = String.valueOf(System.console().readPassword());

                try {
                    ps = Integer.parseInt(p);
                    fw1.write(u + " " + p + "\n");

                } catch (Exception e) {
                    fw2.write(u + " " + p + "\n");

                }
                n--;
            }
            sc.close();
            fw1.close();
            fw2.close();
        } catch (Exception e) {

        } finally {
            new ValidCheck();
            new InvalidCheck();
        }

    }

}

class ValidCheck {
    ValidCheck() {
        File f = null;
        try {
            ArrayList<Integer> list = new ArrayList<Integer>();
            f = new File("valid.txt");
            Scanner sc = new Scanner(f);
            while (sc.hasNextLine()) {
                String s = sc.nextLine();
                StringTokenizer st = new StringTokenizer(s);
                st.nextToken();
                list.add(Integer.parseInt(st.nextToken()));

            }
            Collections.sort(list);
            Collections.reverse(list);

            Iterator it = list.iterator();
            while (it.hasNext()) {
                System.out.println(it.next());
            }
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}

class InvalidCheck extends Thread {

    InvalidCheck() {

        try {
            ArrayList<String> list = new ArrayList<String>();
            File f = new File("invaid.txt");
            Scanner sc = new Scanner(f);
            while (sc.hasNextLine()) {
                String s = sc.nextLine();
                StringTokenizer st = new StringTokenizer(s);
                list.add(st.nextToken());
                st.nextToken();
            }
            Collections.sort(list);
            // Iterator it = list.iterator();
            // while(it.hasNext()){
            // System.out.println(it.next());
            // }
            System.out.println("hihi");
            for (String str : list) {
                System.out.println("" + str);
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
