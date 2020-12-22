import java.io.*;
import java.util.*;
import java.math.*;

class jump{
    
    static int N;
    static BigInteger dp[][];

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        dp = new BigInteger[N][N];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dp[i][j] = BigInteger.valueOf(0);
            }
        }
        dp[0][0] = BigInteger.valueOf(1);
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                int c = Integer.parseInt(st.nextToken());
                if(c == 0) continue;
                if(i + c < N){
                    dp[i+c][j] = dp[i+c][j].add(dp[i][j]);
                }
                if(j + c < N){
                    dp[i][j+c] = dp[i][j+c].add(dp[i][j]);
                }
            }
        }
        System.out.println(dp[N-1][N-1]);
    }
}
