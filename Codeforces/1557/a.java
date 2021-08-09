import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T, N, a[];
    public static void main(String args[]) throws IOException{
        T = nexti();
        while(T-- > 0){
            N = nexti();
            a = new int[N];
            long sum = 0;
            for(int i = 0; i < N; i++){
                a[i] = nexti();
                sum += a[i];
            }
            Integer a2[] = new Integer[N];
            for(int i = 0; i < N; i++) a2[i] = a[i];
            Arrays.sort(a2);
            double x1 = (double)a2[N-1];
            double x2 = (double)(sum-x1) / (N-1);
            pw.printf("%.9f\n", x1+x2);
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

