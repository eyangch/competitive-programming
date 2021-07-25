import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T, N;
    static String s;
    public static void main(String args[]) throws IOException{
        T = Integer.parseInt(next());
        while(T-- > 0){
            N = Integer.parseInt(next());
            s = next();
            Character a[] = new Character[N];
            for(int i = 0; i < N; i++) a[i] = s.charAt(i);
            Arrays.sort(a);
            int ans = 0;
            for(int i = 0; i < N; i++) ans += (s.charAt(i) != a[i] ? 1 : 0);
            pw.println(ans);
        }
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
}
