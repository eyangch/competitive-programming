import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    public static void main(String args[]) throws IOException{
        int T = Integer.parseInt(next());
        while(T-- > 0){
            int N = Integer.parseInt(next());
            if(N == 2){
                pw.println(-1);
                continue;
            }
            int x = 1;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    pw.print(x + " ");
                    x += 2;
                    if(x > N*N) x = 2;
                }
                pw.println();
            }
        }
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
}

