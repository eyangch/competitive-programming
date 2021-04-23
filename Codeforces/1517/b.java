import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
            Integer b[][] = new Integer[N][M];
            int u[] = new int[N];
            int d[] = new int[N];
            Arrays.fill(u, 0);
            Arrays.fill(d, M-1);
            for(int i = 0; i < N; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < M; j++){
                    b[i][j] = Integer.parseInt(st.nextToken());
                }
                Arrays.sort(b[i]);
            }
            int ans[][] = new int[N][M];
            for(int i = 0; i < M; i++){
                for(int j = 0; j < N; j++){
                    ans[j][i] = b[j][d[j]];
                    d[j]--;
                }
                int mv = (int)2e9;
                int mi = 0;
                for(int j = 0; j < N; j++){
                    if(b[j][u[j]] < mv){
                        mv = b[j][u[j]];
                        mi = j;
                    }
                }
                d[mi]++;
                u[mi]++;
                ans[mi][i] = mv;
            }
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    pw.print(ans[i][j] + " ");
                }
                pw.println();
            }
        }
        br.close(); pw.close();
    }
}
