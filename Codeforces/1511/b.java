import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static long T;
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            long g = (long)Math.pow(10, c-1);
            long x = g;
            while(x < (long)Math.pow(10, a-1)){
                x *= 2;
            }
            long y = g;
            while(y < (long)Math.pow(10, b-1)){
                y *= 3;
            }
            pw.println(x + " " + y);
        }
        br.close(); pw.close();    
    }
}
