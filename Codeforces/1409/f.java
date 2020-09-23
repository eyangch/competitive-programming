import java.io.*;
import java.util.*;

public class f {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
		String s = br.readLine();
		String t = br.readLine();
		char a = t.charAt(0), b = t.charAt(1);
		int dp[][][] = new int[202][202][202]; // [first chars][n changes][n first c]
		for(int i = 0; i < 202; i++) {
			for(int j = 0; j < 202; j++) {
				for(int k = 0; k < 202; k++) {
					dp[i][j][k] = -10000000;
				}
			}
		}
		dp[0][0][0] = 0;
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j <= i && j <= K; j++) {
				for(int k = 0; k <= i; k++) {
					if(s.charAt(i-1) == a && k > 0) {
						dp[i][j][k] = Math.max(dp[i][j][k], dp[i-1][j][k-1]);
					}else if(j > 0 && k > 0){
						dp[i][j][k] = Math.max(dp[i][j][k], dp[i-1][j-1][k-1]);
					}
					if(s.charAt(i-1) == b) {
						dp[i][j][k] = Math.max(dp[i][j][k], dp[i-1][j][k] + k);
					}else if(j > 0){
						dp[i][j][k] = Math.max(dp[i][j][k], dp[i-1][j-1][k] + k);
					}
					if(s.charAt(i-1) == a && s.charAt(i-1) == b && k > 0) {
						dp[i][j][k] = Math.max(dp[i][j][k], dp[i-1][j][k-1] + k-1);
					}
					if(a == b && s.charAt(i-1) != a && j > 0 && k > 0) {
						dp[i][j][k] = Math.max(dp[i][j][k], dp[i-1][j-1][k-1] + k-1);
					}
					if(s.charAt(i-1) != a && s.charAt(i-1) != b) {
						dp[i][j][k] = Math.max(dp[i][j][k], dp[i-1][j][k]);
					}
					ans = Math.max(ans, dp[i][j][k]);
				}
			}
		}
		System.out.println(ans);
	}
}
