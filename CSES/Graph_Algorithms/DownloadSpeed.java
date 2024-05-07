import java.io.*;
import java.util.*;

public class DownloadSpeed{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");
	static int N, M, K;
	static int vE[], eNxt[], eTo[], eCap[], eCnt = 0, par[];
	static void addE(int u, int v, int c){
		eNxt[eCnt] = vE[u];
		eTo[eCnt] = v;
		eCap[eCnt] = c;
		vE[u] = eCnt++;
	}
	static int bfs(int k){
		Queue<Integer> q = new ArrayDeque<>();
		Arrays.fill(par, -1);
		par[0] = 0;
		q.add(0);
		while(!q.isEmpty()){
			int v = q.poll();
			for(int i = vE[v]; i != -1; i = eNxt[i]){
				if(par[eTo[i]] == -1 && eCap[i]>>k<<k > 0){
					q.add(eTo[i]);
					par[eTo[i]] = i;
				}
			}
		}
		if(par[N-1] == -1) return 0;
		int z = N-1;
		int flow = 1000000000;
		while(z != 0){
			flow = Math.min(flow, eCap[par[z]]);
			z = eTo[par[z]^1];
		}
		z = N-1;
		while(z != 0){
			eCap[par[z]] -= flow;
			eCap[par[z]^1] += flow;
			z = eTo[par[z]^1];
		}
		return flow;
	}
	public static void main(String[] args) throws IOException{
		N = nextInt(); M = nextInt();
		vE = new int[N];
		Arrays.fill(vE, -1);
		eNxt = new int[2*M];
		eTo = new int[2*M];
		eCap = new int[2*M];
		par = new int[N];
		for(int i = 0; i < M; i++){
			int u = nextInt(), v = nextInt(), c = nextInt();
			u--; v--;
			addE(u, v, c);
			addE(v, u, 0);
		}
		long flow = 0;
		for(int k = 30; k >= 0; k--){
			int kflow;
			while((kflow = bfs(k)) > 0){
				flow += kflow;
			}	
		}
		pw.println(flow);
		br.close(); pw.close();
	}
	static String next() throws IOException{
		while(!st.hasMoreTokens()){
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
	static int nextInt() throws IOException{
		return Integer.parseInt(next());
	}
}