import java.io.*;
import java.util.*;

public class pairup {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("pairup.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("pairup.out"));
		int N = Integer.parseInt(br.readLine());
		int[][] cows = new int[N][2];
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
			cows[i][0] = b;
			cows[i][1] = a;
		}
		Arrays.sort(cows, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		int bot = 0, top = N-1, ret = 0;
		while(bot <= top) {
			int m = Math.min(cows[bot][1], cows[top][1]);
			ret = Math.max(ret, cows[bot][0] + cows[top][0]);
			cows[bot][1] -= m;
			cows[top][1] -= m;
			if(cows[bot][1] <= 0) {
				bot++;
			}if(cows[top][1] <= 0) {
				top--;
			}
		}
		pw.println(ret);
		pw.close();
	}
}
