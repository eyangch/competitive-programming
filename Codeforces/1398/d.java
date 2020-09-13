import java.io.*;
import java.util.*;

public class d {
	
	static int dp[][][], r[], g[], b[];
	
	static int dfs(int R, int G, int B) {
		if(R < 0 || G < 0 || B < 0) {
			return 0;
		}
		if(dp[R][G][B] > -1) {
			return dp[R][G][B];
		}
		int ret = 0;
		if(R > 0) {
			ret = Math.max(ret, dfs(R-1, G, B));
		}
		if(G > 0) {
			ret = Math.max(ret, dfs(R, G-1, B));
		}
		if(B > 0) {
			ret = Math.max(ret, dfs(R, G, B-1));
		}
		if(R > 0 && G > 0) {
			ret = Math.max(ret, dfs(R-1, G-1, B) + r[R-1] * g[G-1]);
		}
		if(R > 0 && B > 0) {
			ret = Math.max(ret, dfs(R-1, G, B-1) + r[R-1] * b[B-1]);
		}
		if(G > 0 && B > 0) {
			ret = Math.max(ret, dfs(R, G-1, B-1) + b[B-1] * g[G-1]);
		}
		dp[R][G][B] = ret;
		return ret;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int R = Integer.parseInt(st.nextToken()), G = Integer.parseInt(st.nextToken()), B = Integer.parseInt(st.nextToken());
		r = new int[R];
		g = new int[G];
		b = new int[B];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < R; i++) {
			r[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < G; i++) {
			g[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < B; i++) {
			b[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(r);
		Arrays.sort(g);
		Arrays.sort(b);
		dp = new int[201][201][201];
		for(int i = 0; i < 201; i++) {
			for(int j = 0; j < 201; j++) {
				for(int k = 0; k < 201; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		dp[0][0][0] = 0;
		System.out.println(dfs(R, G, B));
		br.close();
	}
}
