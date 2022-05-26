import java.io.*;
import java.util.*;

public class d{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int N, M, K, a[];
    static ArrayList<Integer> graph[];
    static boolean works(int x){
        int in[] = new int[N], dp[] = new int[N];
        for(int i = 0; i < N; i++){
            if(a[i] > x) continue;
            for(int j : graph[i]){
                if(a[j] <= x){
                    in[j]++;
                }
            }
        }
        Queue<Integer> q = new LinkedList<Integer>();
        for(int i = 0; i < N; i++){
            if(in[i] == 0 && a[i] <= x){
                q.add(i);
                dp[i] = 1;
            }
        }
        while(!q.isEmpty()){
            int v = q.poll();
            for(int j : graph[v]){
                if(a[j] <= x){
                    dp[j] = Math.max(dp[j], dp[v] + 1);
                    if(--in[j] == 0){
                        q.add(j);
                    }
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(in[i] != 0 || dp[i] >= K) return true;
        }
        return false;
    }
    public static void main(String args[]) throws IOException{
        N = nextInt();
        M = nextInt();
        K = (int)Math.min(1000000000, nextLong());
        a = new int[N];
        for(int i = 0; i < N; i++){
            a[i] = nextInt();
        }
        graph = new ArrayList[N];
        for(int i = 0; i < N; i++) graph[i] = new ArrayList<Integer>();
        for(int i = 0; i < M; i++){
            int u = nextInt(), v = nextInt();
            graph[u-1].add(v-1);
        }
        int lo = 0, hi = 1000000000, mid = 0, ans = -1;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(works(mid)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        pw.println(ans);
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int nextInt() throws IOException{
        return Integer.parseInt(next());
    }
    static long nextLong() throws IOException{
        return Long.parseLong(next());
    }
}
