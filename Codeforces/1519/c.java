import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static int T, N, u[];
    static long s[];
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            N = Integer.parseInt(br.readLine());
            u = new int[N];
            s = new long[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; i++){
                u[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; i++){
                s[i] = Integer.parseInt(st.nextToken());
            }
            ArrayList<Long> ar[] = new ArrayList[N];
            for(int i = 0; i < N; i++){
                ar[i] = new ArrayList<Long>();
            }
            for(int i = 0; i < N; i++){
                ar[u[i]-1].add(s[i]);
            }
            for(int i = 0; i < N; i++){
                Collections.sort(ar[i]);
                Collections.reverse(ar[i]);
                for(int j = 1; j < ar[i].size(); j++){
                    ar[i].set(j, ar[i].get(j) + ar[i].get(j-1));
                }
            }
            long ans[] = new long[N];
            for(int i = 0; i < N; i++){
                for(int j = 1; j <= ar[i].size(); j++){
                    int sz = ar[i].size();
                    int id = sz/j * j;
                    ans[j-1] += ar[i].get(id-1);
                }
            }
            for(int i = 0; i < N; i++){
                pw.print(ans[i] + " ");
            }
            pw.println();
        }
        br.close(); pw.close();
    }
}
