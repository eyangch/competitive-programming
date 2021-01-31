import java.io.*;
import java.util.*;

public final class b1{

    static int N, ans, vil[];
    static ArrayList<Integer> graph[];
    static boolean vis[];

    static void dfs(int id, int par){
        for(int i : graph[id]){
            if(i == par) continue;
            dfs(i, id);
        }
        if(!vis[id] && par > -1){
            ans += 2;
            vis[id] = vis[par] = true;
            int tmp = vil[id];
            vil[id] = vil[par];
            vil[par] = tmp;
        }
    }

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        N = Integer.parseInt(br.readLine());
        graph = new ArrayList[N];
        vis = new boolean[N];
        vil = new int[N];
        for(int i = 0; i < N; i++){
            graph[i] = new ArrayList<Integer>();
            vil[i] = i+1;
        }
        for(int i = 0; i < N-1; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1, b = Integer.parseInt(st.nextToken()) - 1;
            graph[a].add(b);
            graph[b].add(a);
        }
        dfs(0, -1);
        if(!vis[0]){
            ans += 2;
            int tmp = vil[0];
            vil[0] = vil[graph[0].get(0)];
            vil[graph[0].get(0)] = tmp;
        }
        pw.printf("%d\n", ans);
        for(int i = 0; i < N; i++){
            pw.printf("%d ", vil[i]);
        }
        pw.printf("\n");
        br.close();
        pw.close();
    }
}
