import java.io.*;

public class d {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			String s = br.readLine();
			int start = -1;
			for(int i = 1; i < N; i++) {
				if(s.charAt(i) != s.charAt(i-1)) {
					start = i;
					break;
				}
			}
			if(start == -1) {
				System.out.println((N+2)/3);
			}else {
				int cntr = 0;
				int ans = 0;
				for(int i = start; i < start+N; i++) {
					int idx = i%N;
					if(s.charAt(idx) != s.charAt((i-1)%N)) {
						ans += cntr/3;
						cntr = 0;
					}
					cntr++;
				}
				ans += cntr/3;
				System.out.println(ans);
			}
		}
		br.close();
	}
}
