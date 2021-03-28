import java.io.*;
import java.util.*;

public class Solution{
    static int T, X, Y, N, dp[][];
    static String s;
    public static void main(String args[]) throws IOException{
        BufferedReader eat = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter moo = new PrintWriter(System.out);
        T = Integer.parseInt(eat.readLine());
        for(int tc = 1; tc <= T; tc++){
            moo.print("Case #" + tc + ": ");
            StringTokenizer st = new StringTokenizer(eat.readLine());
            X = Integer.parseInt(st.nextToken());
            Y = Integer.parseInt(st.nextToken());
            s = st.nextToken();
            N = s.length();
            dp = new int[N][2];
            for(int i = 0; i < N; i++) dp[i][0] = dp[i][1] = 10000000;
            if(s.charAt(0) == 'C' || s.charAt(0) == '?') dp[0][0] = 0;
            if(s.charAt(0) == 'J' || s.charAt(0) == '?') dp[0][1] = 0;
            for(int i = 1; i < N; i++){
                if(s.charAt(i) == 'C' || s.charAt(i) == '?'){
                    dp[i][0] = Math.min(dp[i-1][0], dp[i-1][1] + Y);
                }
                if(s.charAt(i) == 'J' || s.charAt(i) == '?'){
                    dp[i][1] = Math.min(dp[i-1][0] + X, dp[i-1][1]);
                }
            }
            moo.println(Math.min(dp[N-1][0], dp[N-1][1]));
        }
        eat.close(); moo.close();
    }
}
