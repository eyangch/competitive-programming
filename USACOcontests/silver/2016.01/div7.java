import java.io.*;
import java.util.*;

public class div7 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("div7.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("div7.out")));
		int N = Integer.parseInt(br.readLine());
		int cows[] = new int[N];
		for(int i = 0; i < N; i++) {
			cows[i] = Integer.parseInt(br.readLine()) % 7;
		}
		int pfx[] = new int[N];
		pfx[0] = cows[0];
		for(int i = 1; i < N; i++) {
			pfx[i] = pfx[i-1] + cows[i];
			pfx[i] %= 7;
		}
		long ans = 0;
		int cnt[] = new int[7];
		Arrays.fill(cnt, -2);
		cnt[0] = -1;
		for(int i = 0; i < N; i++) {
			if(cnt[pfx[i]] == -2) {
				cnt[pfx[i]] = i;
			}else {
				ans = Math.max(ans, i-cnt[pfx[i]]);
			}
		}
		pw.println(ans);
		br.close();
		pw.close();
	}
}
