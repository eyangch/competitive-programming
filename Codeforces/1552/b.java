import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T, N, r[][];
    public static void main(String args[]) throws IOException{
        T = nexti();
        while(T-- > 0){
            N = nexti();
            r = new int[N][5];
            for(int i = 0; i < N; i++){
                for(int j = 0; j < 5; j++){
                    r[i][j] = nexti();
                }
            }
            int s = 0;
            for(int i = 1; i < N; i++){
                int cnt = 0;
                for(int j = 0; j < 5; j++){
                    if(r[s][j] > r[i][j]) cnt++;
                }
                if(cnt >= 3) s = i;
            }
            boolean good = true;
            for(int i = 0; i < s; i++){
                int cnt = 0;
                for(int j = 0; j < 5; j++){
                    if(r[s][j] > r[i][j]) cnt++;
                }
                if(cnt >= 3){
                    good = false;
                    break;
                }
            }
            if(!good) pw.println(-1);
            else pw.println(s+1);
        }
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int nexti() throws IOException{
        return Integer.parseInt(next());
    }
}
