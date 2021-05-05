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
            int a[] = new int[N];
            long occ[] = new long[2*N+20];
            Arrays.fill(occ, 0);
            for(int i = 0; i < N; i++){
                a[i] = Integer.parseInt(next());
                a[i] += N-i;
                occ[a[i]]++;
            }
            long ans = 0;
            for(int i = 0; i < 2*N+20; i++){
                long x = occ[i];
                ans += x * (x-1) / 2;
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
