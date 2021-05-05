import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    public static void main(String args[]) throws IOException{
        int T = Integer.parseInt(next());
        while(T-- > 0){
            long N = Integer.parseInt(next());
            long x = 1;
            int ans = 0;
            while(x <= N){
                for(long i = 1; i < 10; i++){
                    if(i * x > N) break;
                    ans++;
                }
                x = x * 10 + 1;
            }
            pw.println(ans);
        }
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
}

