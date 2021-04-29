import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static long T, r, b, d;
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            r = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            if(r < b){
                long tmp = r;
                r = b;
                b = tmp;
            }
            if((d + 1) * b < r){
                pw.println("NO");
            }else{
                pw.println("YES");
            }
        }
        br.close(); pw.close();
    }
}
