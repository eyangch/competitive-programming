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
            String s = next();
            ArrayList<Integer> ar = new ArrayList<Integer>();
            for(int i = 0; i < N; i++){
                if(s.charAt(i) == '*'){
                    ar.add(i - ar.size());
                }
            }
            if(ar.size() == 0){
                pw.println(0);
                continue;
            }
            int loc = ar.get(ar.size() / 2);
            long ans = 0;
            for(int i : ar){
                ans += (long)(Math.abs(i - loc));
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
