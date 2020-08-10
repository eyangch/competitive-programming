import java.io.*;
import java.util.*;

public class multimoo {
	
	static class data implements Comparable<data>{
		int id, n1, n2;
		public data(int id, int n1, int n2) {
			this.id = id;
			this.n1 = n1;
			this.n2 = n2;
		}
		@Override
		public int compareTo(data b) {
			if(this.id == b.id) {
				if(this.n1 == b.n1) {
					return this.n2 - b.n2;
				}
				return this.n1 - b.n1;
			}
			return this.id - b.id;
		}
	}
	
	static int N;
	static int[][] b, ids;
	static ArrayList<Integer> idnum, idval;
	static int[] dx = {-1, 1, 0, 0}, dy = {0, 0, 1, -1};
	static boolean[][] vis2;
	static ArrayList<Integer>[] graph;
	static TreeSet<Integer> visg;
	static TreeSet<data> adone;
	
	static int ffill(int x, int y, int id) {
		ids[x][y] = id;
		int ret = 1;
		for(int i = 0; i < 4; i++) {
			int nx = x+dx[i], ny = y+dy[i];
			if(nx < 0 || nx >= N || ny < 0 || ny >= N || b[x][y] != b[nx][ny] || ids[nx][ny] != -1) continue;
			ret += ffill(nx, ny, id);
		}
		return ret;
	}
	
	static void ffill2(int x, int y, int id){
	    if(ids[x][y] != id){
	        graph[id].add(ids[x][y]);
	    }else{
	        if(vis2[x][y]) return;
	        vis2[x][y] = true;
	        for(int i = 0; i < 4; i++){
	            int nx = x+dx[i], ny = y+dy[i];
	            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
	            ffill2(nx, ny, id);
	        }
	    }
	}
	
	static int dfs(int id, int a, int b){
	    if(visg.contains(id) || adone.contains(new data(id, a, b))) {
	    	return 0;
	    }
	    adone.add(new data(id, a, b));
	    visg.add(id);
	    int ret = idval.get(id);
	    for(int i : graph[id]){
	        if(idnum.get(i) == a || idnum.get(i) == b){
	            ret += dfs(i, a, b);
	        }
	    }
	    return ret;
	}
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("multimoo.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("multimoo.out")));
		N = Integer.parseInt(br.readLine());
		b = new int[N][N];
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				b[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		ids = new int[N][N];
		for(int i = 0; i < N; i++) {
			Arrays.fill(ids[i], -1);
		}
		int idcnt = 0;
		idnum = new ArrayList<Integer>();
		idval = new ArrayList<Integer>();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(ids[i][j] != -1) continue;
				idnum.add(b[i][j]);
				idval.add(ffill(i, j, idcnt));
				idcnt++;
			}
		}
		vis2 = new boolean[N][N];
		graph = new ArrayList[idcnt];
		for(int i = 0; i < idcnt; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < N; i++) {
	        for(int j = 0; j < N; j++) {
	            if(vis2[i][j]) continue;
	            ffill2(i, j, ids[i][j]); 
	        }
	    }
		for(int i = 0; i < idcnt; i++) {
			TreeSet<Integer> ts = new TreeSet<>(graph[i]);
			graph[i] = new ArrayList<>(ts);
		}
		int ans = 0;
	    int ans2 = 0;
	    for(int i : idval) {
	        ans = Math.max(ans, i);
	    }
	    adone = new TreeSet<data>();
	    for(int i = 0; i < idcnt; i++) {
	    	for(int j : graph[i]) {
	    		if(adone.contains(new data(i, idnum.get(i), idnum.get(j)))) {
	    			continue;
	    		}
	    		visg = new TreeSet<Integer>();
	    		int x = dfs(i, idnum.get(i), idnum.get(j));
	    		ans2 = Math.max(ans2, x);
	    	}
	    }
	    pw.println(ans);
	    pw.println(ans2);
		br.close();
		pw.close();
	}
}
