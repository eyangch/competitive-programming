import java.util.*;

public class d {
	
	static double dp[][][];
	
	static void fn1() {
		for(int i = 0; i < 101; i++) {
			for(int j = 0; j < 101; j++) {
				for(int k = 0; k < 101; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
	}
	
	static double dfs(int r, int p, int s) {
		if(dp[r][p][s] >= 0) {
			return dp[r][p][s];
		}
		double ans = 0;
		int cnt = 0;
		double tcomb = r*p+r*s+p*s;
		if(r > 0 && p > 0) {
			cnt++;
			ans += dfs(r-1, p, s) * (r*p/tcomb);
		}
		if(s > 0 && r > 0) {
			cnt++;
			ans += dfs(r, p, s-1) * (r*s/tcomb);
		}
		if(p > 0 && s > 0) {
			cnt++;
			ans += dfs(r, p-1, s) * (p*s/tcomb);
		}
		if(cnt == 0) {
			ans = 0;
		}
		dp[r][p][s] = ans;
		return ans;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int r = in.nextInt(), s = in.nextInt(), p = in.nextInt();
		dp = new double[101][101][101];
		fn1();
		for(int i = 0; i < 101; i++) {
			dp[i][0][0] = 1;
		}
		dfs(r, p, s);
		System.out.print(dp[r][p][s] + " ");
		fn1();
		for(int i = 0; i < 101; i++) {
			dp[0][0][i] = 1;
		}
		dfs(r, p, s);
		System.out.print(dp[r][p][s] + " ");
		fn1();
		for(int i = 0; i < 101; i++) {
			dp[0][i][0] = 1;
		}
		dfs(r, p, s);
		System.out.println(dp[r][p][s]);
		in.close();
	}
}
