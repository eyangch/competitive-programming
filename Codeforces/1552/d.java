import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T, N, a[];
    static boolean ok;
    static void dfs(int i, int sum){
        if(sum == a[N-1]){
            ok = true;
            return;
        }
        if(ok || i == N-1) return;
        dfs(i+1, sum);
        if(ok) return;
        dfs(i+1, sum + a[i]);
        if(ok) return;
        dfs(i+1, sum - a[i]);
    }
    public static void main(String args[]) throws IOException{
        T = nexti();
        while(T-- > 0){
            N = nexti();
            a = new int[N];
            for(int i = 0; i < N; i++) a[i] = nexti();
            ok = false;
            for(int i = 0; i < N; i++){
                dfs(0, 0);
                int tmp = a[i];
                a[i] = a[N-1];
                a[N-1] = tmp;
            }
            pw.println((ok ? "YES" : "NO"));
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

