import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T;
    public static void main(String args[]) throws IOException{
        T = Integer.parseInt(next());
        while(T-- > 0){
            int N = Integer.parseInt(next());
            boolean vis[] = new boolean[26];
            Arrays.fill(vis, false);
            String s = next();
            s += '0';
            boolean good = true;
            for(int i = 0; i < N; i++){
                if(s.charAt(i) != s.charAt(i+1)){
                    if(vis[s.charAt(i)-'A']){
                        good = false;
                        break;
                    }
                    vis[s.charAt(i)-'A'] = true;
                }
            }
            pw.println((good ? "YES" : "NO"));
        }
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
}

