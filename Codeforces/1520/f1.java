import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int qry(int l, int r) throws IOException{
        pw.println("? " + l + " " + r);
        pw.flush();
        return Integer.parseInt(next());
    }
    public static void main(String args[]) throws IOException{
        int N = Integer.parseInt(next()), T = Integer.parseInt(next()), K = Integer.parseInt(next());
        int lo = 1, hi = N, mid = 0, ans = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            int x = qry(1, mid);
            if(mid - x >= K){
                hi = mid-1;
                ans = mid;
            }else{
                lo = mid+1;
            }
        }
        pw.println("! " + ans);
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
}
