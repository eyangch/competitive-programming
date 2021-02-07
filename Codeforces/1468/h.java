import java.io.*;
import java.util.*;

public final class h{

    static int T, N, K, M, b[], pfx[];

    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        T = Integer.parseInt(in.readLine());
        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken()) / 2;
            M = Integer.parseInt(st.nextToken());
            b = new int[M];
            pfx = new int[N+1];
            st = new StringTokenizer(in.readLine());
            for(int i = 0; i < M; i++){
                b[i] = Integer.parseInt(st.nextToken());
            }
            int pv = 1;
            for(int i = 0; i < M; i++){
                for(int j = pv; j < b[i]; j++){
                    pfx[j] = pfx[j-1] + 1;
                }
                pfx[b[i]] = pfx[b[i]-1];
                pv = b[i]+1;
            }
            for(int i = b[M-1]+1; i <= N; i++){
                pfx[i] = pfx[i-1] + 1;
            }
            if(N % (2*K) != M % (2*K)){
                out.printf("nO\n");
                continue;
            }
            boolean good = false;
            for(int i = 0; i < M; i++){
                int lo = pfx[b[i]];
                int hi = pfx[N] - pfx[b[i]];
                if(lo >= K && hi >= K){
                    good = true;
                    break;
                }
            }
            out.printf(good ? "yEs\n" : "no\n");
        }
        in.close();
        out.close();
    }
}
