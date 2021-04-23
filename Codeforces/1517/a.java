import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            long N = Long.parseLong(br.readLine());
            if(N % 2050L > 0){
                pw.println(-1);
                continue;
            }
            long d = N / 2050L;
            String ds = Long.toString(d);
            int ans = 0;
            for(int i = 0; i < ds.length(); i++){
                ans += ds.charAt(i) - '0';
            }
            pw.println(ans);
        }
        br.close(); pw.close();
    }
}
