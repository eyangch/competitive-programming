import java.io.*;

public class escape {
	static int dfs(int N, int[] cows, int cow, int add) {
		int num = cows[cow];
		int nc = add;
		while(num > 0 && nc > 0) {
			int n1 = num % 10;
			int n2 = nc % 10;
			if(n1 + n2 > 9)
				return 0;
			num /= 10;
			nc /= 10;
		}
		int m = 0;
		add += cows[cow];
		for(int i = cow+1; i < N; i++) 
			m = Math.max(m, dfs(N, cows, i, add));
		return m+1;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("escape.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("escape.out"));
		int N = Integer.parseInt(br.readLine());
		int[] cows = new int[N];
		for(int i = 0; i < N; i++)
			cows[i] = Integer.parseInt(br.readLine());
		int m = 0;
		for(int i = 0; i < N - 1; i++)
			m = Math.max(m, dfs(N, cows, i, 0));
		pw.println(m);
		br.close();
		pw.close();
	}
}
