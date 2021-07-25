import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T, N, K, p[][];
    static boolean f[];
    static int hemi(int a1, int a2, int b){
        if(a1 > a2){
            int tmp = a1;
            a1 = a2;
            a2 = tmp;
        }
        if(b > a1 && b < a2) return 0;
        return 1;
    }
    public static void main(String args[]) throws IOException{
        T = nexti();
        while(T-- > 0){
            N = nexti();
            K = nexti();
            p = new int[K][2];
            f = new boolean[2*N];
            Arrays.fill(f, false);
            for(int i = 0; i < K; i++){
                p[i][0] = nexti() - 1;
                p[i][1] = nexti() - 1;
                f[p[i][0]] = true;
                f[p[i][1]] = true;
            }
            int ans = 0;
            int rem = N-K;
            ans += rem * (rem-1) / 2;
            for(int i = 0; i < K; i++){
                for(int j = i+1; j < K; j++){
                    int h1 = hemi(p[i][0], p[i][1], p[j][0]);
                    int h2 = hemi(p[i][0], p[i][1], p[j][1]);
                    if(h1 != h2) ans++;
                }
                int v0 = 0, v1 = 0;
                for(int j = 0; j < 2*N; j++){
                    if(f[j]) continue;
                    if(hemi(p[i][0], p[i][1], j) == 0) v0++;
                    else v1++;
                }
                int v = Math.min(v0, v1);
                ans += v;
            }
            pw.println(ans);
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

