import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static long MOD = 1000000007;
    static long fact[];
    static int T, N, K;
    static long dp[][];
    static long inv(long x){
        long ret = 1;
        long e = MOD-2;
        while(e > 0){
            if((e&1) > 0) ret = ret * x % MOD;
            x = x * x % MOD;
            e >>= 1;
        }
        return ret;
    }
    static long nCr(int n, int r){
        return fact[n] * inv(fact[r] * fact[n-r] % MOD) % MOD;
    }
    public static void main(String args[]) throws IOException{
        fact = new long[250000];
        fact[0] = 1;
        for(int i = 1; i < 250000; i++){
            fact[i] = fact[i-1] * i % MOD;
        }
        T = nexti();
        while(T-- > 0){
            N = nexti();
            K = nexti();
            long val = 0;
            for(int i = 0; i < N; i += 2){
                val = (val + nCr(N, i)) % MOD;
            }
            long p2n = 1;
            for(int i = 0; i < N; i++){
                p2n = p2n * 2 % MOD;
            }
            dp = new long[K+1][2];
            for(int i = 0; i <= K; i++) for(int j = 0; j < 2; j++) dp[i][j] = 0;
            dp[0][0] = 1;
            for(int i = 1; i <= K; i++){
                dp[i][1] = dp[i-1][1] * p2n % MOD;
                dp[i][0] = val * dp[i-1][0] % MOD;
                if(N % 2 == 0){
                    dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
                }else{
                    dp[i][0] = (dp[i][0] + dp[i-1][0]) % MOD;
                }
            }
            pw.println((dp[K][0] + dp[K][1]) % MOD);
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

