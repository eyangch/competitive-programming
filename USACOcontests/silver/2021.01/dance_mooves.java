import java.io.*;
import java.util.*;

public final class dance_mooves{

    static int N, K;
    static int a[], b[], cow[], mp[];
    static ArrayList<Integer> vis[];
    static HashSet<Integer> cur;
    static boolean dvis[], dvis2[];
    static int ans[];
    
    static void dfs1(int id){
        while(true){
            if(dvis[id]) return;
            dvis[id] = true;
            cur.addAll(vis[id]);
            id = mp[id];
        }
    }
    
    static void dfs2(int id, int sz){
        while(true){
            if(dvis2[id]) return;
            dvis2[id] = true;
            ans[id] = sz;
            id = mp[id];
        }
    }

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        PrintWriter pw = new PrintWriter(System.out);
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        a = new int[K];
        b = new int[K];
        cow = new int[N];
        mp = new int[N];
        dvis = new boolean[N];
        dvis2 = new boolean[N];
        vis = new ArrayList[N];
        ans = new int[N];
        for(int i = 0; i < N; i++){
            cow[i] = i;
            mp[i] = i;
            vis[i] = new ArrayList<Integer>();
            vis[i].add(i);
        }
        for(int i = 0; i < K; i++){
            st = new StringTokenizer(br.readLine());
            a[i] = Integer.parseInt(st.nextToken())-1;
            b[i] = Integer.parseInt(st.nextToken())-1;
            int tmp = cow[a[i]];
            cow[a[i]] = cow[b[i]];
            cow[b[i]] = tmp;
            vis[cow[a[i]]].add(a[i]);
            vis[cow[b[i]]].add(b[i]);
            mp[cow[a[i]]] = a[i];
            mp[cow[b[i]]] = b[i];
        }
        for(int i = 0; i < N; i++){
            if(dvis[i]) continue;
            cur = new HashSet<Integer>();
            dfs1(i);
            dfs2(i, cur.size());
        }
        for(int i = 0; i < N; i++){
            pw.println(ans[i]);
        }
        pw.close();
    }
}
