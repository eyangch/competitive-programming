import java.io.*;
import java.util.*;

public final class a{

    static int T, N, a[], BIT[], dp[];
    static ArrayList<Integer> p[];

    static void upd(int id, int x){
        for(int i = id; i <= N; i += i & -i){
            BIT[i] = Math.max(BIT[i], x);
        }
    }

    static int qry(int id){
        int ret = 0;
        for(int i = id; i > 0; i -= i & -i){
            ret = Math.max(ret, BIT[i]);
        }
        return ret;
    }

    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        T = Integer.parseInt(in.readLine());
        while(T-- > 0){
            N = Integer.parseInt(in.readLine());
            a = new int[N];
            p = new ArrayList[N];
            dp = new int[N];
            BIT = new int[2*N+1];
            for(int i = 0; i < N; i++){
                p[i] = new ArrayList<Integer>();
            }
            StringTokenizer st = new StringTokenizer(in.readLine());
            for(int i = 0; i < N; i++){
                a[i] = Integer.parseInt(st.nextToken());
            }
            Stack<Integer> s = new Stack<Integer>();
            for(int i = 0; i < N; i++){
                while(s.size() > 0 && a[s.peek()] <= a[i]){
                    p[i].add(s.pop());
                }
                s.push(i);
            }
            for(int i = 0; i < N; i++){
                dp[i] = qry(a[i]) + 1;
                upd(a[i], dp[i]);
                if(i == 0) upd(1, 1);
                for(int j : p[i]){
                    upd(a[j], dp[j] + 1);
                }
            }
            out.println(qry(N));
        }
        in.close();
        out.close();
    }
}
