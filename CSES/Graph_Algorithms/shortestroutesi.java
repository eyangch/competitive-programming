import java.io.*;
import java.util.*;

public class shortestroutesi{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");

	static int N, M;
	static ArrayList<Node>[] G;

	static void dij(){
		long d[] = new long[N];
		Arrays.fill(d, 1000000000000000L);
		d[0] = 0;
		Queue<Node> q = new PriorityQueue<>();
		q.add(new Node(0, 0));
		while(!q.isEmpty()){
			Node cur = q.poll();
			if(cur.d != d[cur.v]) continue;
			for(Node c : G[cur.v]){
				long nd = cur.d + c.d;
				if(nd < d[c.v]){
					d[c.v] = nd;
					q.add(new Node(c.v, nd));
				}
			}
		}
		for(long i : d){
			pw.print(i + " ");
		}
		pw.println();
	}

	public static void main(String args[]) throws IOException{
		N = nextInt();
		M = nextInt();
		G = new ArrayList[N];
		for(int i = 0; i < N; i++){
			G[i] = new ArrayList();
		}
		for(int i = 0; i < M; i++){
			int a = nextInt(), b = nextInt(), c = nextInt();
			a--; b--;
			G[a].add(new Node(b, c));
		}
		dij();
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
	static class Node implements Comparable<Node>{
		int v;
		long d;
		Node(int v, long d){
			this.v = v; this.d = d;
		}
		public int compareTo(Node n){
			if(d > n.d) return 1;
			else if(d == n.d) return 0;
			else return -1;
		}
	}
}