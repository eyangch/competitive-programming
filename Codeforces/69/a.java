import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class a{

    static int N, x, y, z;

    public static void main(String args[]) throws IOException{
        Scanner eat = new Scanner(System.in);
        N = eat.nextInt();
        for(int i = 0; i < N; i++){
            x += eat.nextInt();
            y += eat.nextInt();
            z += eat.nextInt();
        }
        out.println((x == 0 && y == 0 && z == 0) ? "YES" : "NO");
        eat.close();
    }
}
