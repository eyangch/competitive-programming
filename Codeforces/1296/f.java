import java.io.*;
import java.util.*;

public class f{

    static int N, M, d[][], be[][], u[], v[];
    static ArrayList<Integer> graph[];
    static q qs[];

    static void dfs(int s, int id, int p, int di){
        d[s][id] = p;
        for(int i : graph[id]){
            if(i == p) continue;
            dfs(s, i, id, di+1);
        }
    }

    public static void main(String args[]) throws IOException{
        BufferedReader eat = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter moo = new PrintWriter(System.out);
        N = Integer.parseInt(eat.readLine());
        graph = new ArrayList[N];
        for(int i = 0; i < N; i++) graph[i] = new ArrayList<Integer>();
        u = new int[N-1];
        v = new int[N-1];
        for(int i = 0; i < N-1; i++){
            StringTokenizer st = new StringTokenizer(eat.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1, y = Integer.parseInt(st.nextToken()) - 1;
            u[i] = x;
            v[i] = y;
            graph[x].add(y);
            graph[y].add(x);
        }
        d = new int[N][N];
        for(int i = 0; i < N; i++){
            dfs(i, i, -1, 0);
        }
        M = Integer.parseInt(eat.readLine());
        qs = new q[M];
        for(int i = 0; i < M; i++){
            StringTokenizer st = new StringTokenizer(eat.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1, b = Integer.parseInt(st.nextToken()) - 1, g = Integer.parseInt(st.nextToken());
            qs[i] = new q(a, b, g);
        }
        Arrays.sort(qs);
        be = new int[N][N];
        boolean f = false;
        for(int i = 0; i < M; i++){
            int a = qs[i].a, b = qs[i].b, g = qs[i].g;
            f = false;
            while(a != b){
                int nxt = d[b][a];
                if(be[a][nxt] <= g){
                    f = true;
                    be[a][nxt] = be[nxt][a] = g;
                }
                a = nxt;
            }
            if(!f){
                break;
            }
        }
        if(f){
            for(int i = 0; i < N-1; i++){
                int x = be[u[i]][v[i]];
                moo.print((x == 0 ? 1 : x) + " ");
            }
            moo.println();
        }else{
            moo.println(-1);
        }
        eat.close(); moo.close();
    }

    static class q implements Comparable<q>{
        int a, b, g;
        q(int a, int b, int g){
            this.a = a;
            this.b = b;
            this.g = g;
        }
        public int compareTo(q x){
            return x.g - this.g;
        }
    }
}
