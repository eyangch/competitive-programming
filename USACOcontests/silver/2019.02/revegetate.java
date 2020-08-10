import java.io.*;
import java.util.*;

public class revegetate {
	
	static int N, M;
	static ArrayList<ArrayList<Integer>> graph;
	static ArrayList<ArrayList<Integer>> graph2;
	static boolean[][] vis;
	static int[] gid;
	
	static boolean dfs(int x, int state) {
		if(vis[x][state]) {
			return true;
		}
		vis[x][state] = true;
		gid[x] &= (int)Math.pow(2, state);
		if(gid[x] == 0) {
			return false;
		}
		for(int i = 0; i < graph.get(x).size(); i++) {
			boolean ok = dfs(graph.get(x).get(i), state ^ graph2.get(x).get(i));
			if(!ok) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("revegetate.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("revegetate.out")));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		graph = new ArrayList<ArrayList<Integer>>(N);
		graph2 = new ArrayList<ArrayList<Integer>>(N);
		for(int i = 0; i < N; i++) {
			graph.add(new ArrayList<Integer>());
			graph2.add(new ArrayList<Integer>());
		}
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			char sd = st.nextToken().charAt(0);
			int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
			graph.get(u-1).add(v-1);
			graph.get(v-1).add(u-1);
			graph2.get(u-1).add(sd == 'S' ? 0 : 1);
			graph2.get(v-1).add(sd == 'S' ? 0 : 1);
		}
		vis = new boolean[N][2];
		gid = new int[N];
		Arrays.fill(gid, 3);
		int ans = 0;
		for(int i = 0; i < N; i++) {
			if(vis[i][0] || vis[i][1]) continue;
			boolean ok = dfs(i, 0);
			if(!ok) {
				ans = -1;
				break;
			}
			ans++;
		}
		if(ans == -1) {
			pw.println(0);
		}else {
			pw.print(1);
			for(int i = 0; i < ans; i++) {
				pw.print(0);
			}
			pw.println();
		}
		br.close();
		pw.close();
	}
}
