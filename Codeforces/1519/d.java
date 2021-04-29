import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static int N;
    static long a[], b[];
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        N = Integer.parseInt(br.readLine());
        a = new long[N];
        b = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            b[i] = Integer.parseInt(st.nextToken());
        }
        long val = 0;
        for(int i = 0; i < N; i++){
            val += a[i] * b[i];
        }
        long ans = val;
        for(int i = 0; i < N; i++){
            long cv = val;
            for(int j = 1; i + j < N && i - j >= 0; j++){
                cv -= a[i+j] * b[i+j] + a[i-j] * b[i-j];
                cv += a[i+j] * b[i-j] + a[i-j] * b[i+j];
                ans = (long)Math.max(ans, cv);
            }
        }
        for(int i = 1; i < N; i++){
            long cv = val;
            for(int j = 1; i-1 + j < N && i - j >= 0; j++){
                cv -= a[i-1+j] * b[i-1+j] + a[i-j] * b[i-j];
                cv += a[i-1+j] * b[i-j] + a[i-j] * b[i-1+j];
                ans = (long)Math.max(ans, cv);
            }
        }
        pw.println(ans);
        br.close(); pw.close();
    }
}
