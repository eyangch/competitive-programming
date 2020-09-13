import java.io.*;
import java.util.*;

public class d {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a[] = new int[N], pfx[][] = new int[N][N];
			for(int i = 0; i < N; i++) {
				a[i] = Integer.parseInt(st.nextToken()) - 1;
				for(int j = i; j < N; j++) {
					pfx[a[i]][j]++;
				}
			}
			long ans = 0;
			for(int i = 1; i < N; i++) {
				for(int j = i+1; j < N; j++) {
					ans += pfx[a[j]][i-1] * (pfx[a[i]][N-1] - pfx[a[i]][j]);
				}
			}
			System.out.println(ans);
		}
	}
}
