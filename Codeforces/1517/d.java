import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static int N, M, K;
    static ArrayList<Integer> graph[][];
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        if(K % 2 == 1){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    pw.print("-1 ");
                }
                pw.println();
            }
            br.close(); pw.close();
            return;
        }
        graph = new ArrayList[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                graph[i][j] = new ArrayList<Integer>();
            }
        }
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M-1; j++){
                int w = Integer.parseInt(st.nextToken());
                graph[i][j].add(w);
            }
        }
        for(int i = 0; i < N; i++){
            graph[i][M-1].add(0);
        }
        for(int i = 0; i < N-1; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++){
                int w = Integer.parseInt(st.nextToken());
                graph[i][j].add(w);
            }
        }
        K /= 2;
        for(int i = 0; i < M; i++) graph[N-1][i].add(0);
        long ans[][][] = new long[K+1][N][M];
        for(int i = 0; i < N; i++){
            Arrays.fill(ans[0][i], 0);
        }
        for(int i = 1; i <= K; i++){
            for(int x = 0; x < N; x++){
                for(int y = 0; y < M; y++){
                    long cur = (long)1e17;
                    if(x < N-1){
                        cur = (long)Math.min(cur, graph[x][y].get(1) + ans[i-1][x+1][y]);
                    }
                    if(y < M-1){
                        cur = (long)Math.min(cur, graph[x][y].get(0) + ans[i-1][x][y+1]);
                    }
                    if(x > 0){
                        cur = (long)Math.min(cur, graph[x-1][y].get(1) + ans[i-1][x-1][y]);
                        //pw.println("CUR: " + cur + " X: " + x + " Y: " + y + " get = " + graph[x-1][y].get(0));
                    }
                    if(y > 0){
                        cur = (long)Math.min(cur, graph[x][y-1].get(0) + ans[i-1][x][y-1]);
                    }
                    ans[i][x][y] = cur;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                pw.print(ans[K][i][j] * 2 + " ");
            }
            pw.println();
        }
        br.close(); pw.close();
    }
    static class pii implements Comparable<pii>{
        int f, s, k;
        pii(int f, int s, int k){
            this.f = f;
            this.s = s;
            this.k = k;
        }
        public int compareTo(pii x){
            return Integer.compare(f, x.f);
        }
    }
}
