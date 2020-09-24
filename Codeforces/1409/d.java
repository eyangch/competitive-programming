import java.io.*;
import java.util.*;

public class d {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String sn = st.nextToken();
			int s = Integer.parseInt(st.nextToken());
			int[] a = new int[20];
			for(int i = 0; i < sn.length(); i++) {
				a[i] = sn.charAt(sn.length()-1-i) - '0';
			}
			int ans[] = new int[20];
			for(int i = 0; i < 19; i++) {
				if(a[i] == 0) continue;
				int sum = 0;
				for(int j = 0; j < 20; j++) {
					sum += a[j];
				}
				if(sum <= s) {
					break;
				}
				ans[19-i] = 10-a[i];
				a[i] = 0;
				int ptr = i+1;
				while(ptr < 20) {
					a[ptr]++;
					if(a[ptr] == 10) {
						a[ptr] = 0;
						ptr++;
					}else {
						break;
					}
				}
			}
			boolean start = false;
			for(int i = 0; i < 20; i++) {
				if(ans[i] > 0) {
					start = true;
				}
				if(start) {
					System.out.print(ans[i]);
				}
			}
			if(!start) {
				System.out.print(0);
			}
			System.out.println();
		}
	}
}
