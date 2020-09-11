import java.io.*;
import java.util.*;

public class c {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		long a[][] = new long[N][N], h[] = new long[4100], v[] = new long[4100];
		Arrays.fill(h, 0);
		Arrays.fill(v, 0);
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				a[i][j] = Long.parseLong(st.nextToken());
				h[2000+i-j] += a[i][j];
				v[i+j] += a[i][j];
			}
		}
		long max1 = 0, max2 = 0;
		int x1 = 2, y1 = 2, x2 = 2, y2 = 1;
		for(int i = 0; i < N; i++) {
			for(int j = i%2; j < N; j+=2) {
				long val = h[2000+i-j] + v[i+j] - a[i][j];
				if(val > max1) {
					max1 = val;
					x1 = i+1;
					y1 = j+1;
				}
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = (i+1)%2; j < N; j+=2) {
				long val = h[2000+i-j] + v[i+j] - a[i][j];
				if(val > max2) {
					max2 = val;
					x2 = i+1;
					y2 = j+1;
				}
			}
		}
		System.out.println(max1 + max2);
		System.out.println(x1 + " " + y1 + " " + x2 + " " + y2);
		br.close();
	}
}
