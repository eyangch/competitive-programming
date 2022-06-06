import java.io.*;
import java.util.*;
import java.util.Map.Entry;
 
public class e{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T, N, K, a[];
    static class segtree{
        int N, a[], n[];
        segtree(int N){
            this.N = N;
            a = new int[4*N+1000];
            n = new int[4*N+1000];
        }
        void upd(int i, int x, int v, int l, int r){
            if(i > r || i < l) return;
            if(l == r){
                a[v] += x * i;
                n[v] += x;  
            }else{
                upd(i, x, v*2, l, (l+r)/2);
                upd(i, x, v*2+1, (l+r)/2+1, r);
                a[v] = a[v*2] + a[v*2+1];
                n[v] = n[v*2] + n[v*2+1];
            }
        }
        int qry(int x, int v, int l, int r){
            if(l == r){
                return Math.min(n[v], x/l);
            }
            if(a[v*2] > x){
                return qry(x, v*2, l, (l+r)/2);
            }else{
                return qry(x-a[v*2], v*2+1, (l+r)/2+1, r) + n[v*2];
            }
        }
    }
    public static void main(String args[]) throws IOException{
        T = nextInt();
        while(T-- > 0){
            N = nextInt(); K = nextInt();
            a = new int[N];
            HashMap<Integer, Integer> m = new HashMap<>();
            for(int i = 0; i < N; i++){
                a[i] = nextInt();
                if(m.containsKey(a[i])) m.put(a[i], m.get(a[i])+1);
                else m.put(a[i], 1);
            }
            int gaps = 0;
            segtree s = new segtree(N);
            for(Entry<Integer, Integer> e : m.entrySet()){
                s.upd(e.getValue(), 1, 1, 1, N);
            }
            int ans = 10000000;
            for(int i = 0; i <= N; i++){
                if(K < gaps) break;
                int cur = s.n[1] - s.qry(K, 1, 1, N);
                ans = Math.min(cur, ans);
                if(!m.containsKey(i)) gaps++;
                else{
                    s.upd(m.get(i), -1, 1, 1, N);
                }
            }
            pw.println(ans);
        }
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int nextInt() throws IOException{
        return Integer.parseInt(next());
    }
}
