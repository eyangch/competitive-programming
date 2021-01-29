import java.io.*;
import java.util.*;

public final class b{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            long K = Long.parseLong(st.nextToken());
            long ans = 0;
            long p[] = new long[N];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < N; i++){
                p[i] = Long.parseLong(st.nextToken());
            }
            long sum = p[0];
            for(int i = 1; i < N; i++){
                double v1 = 100 * p[i] - K * sum;
                long add = (long)Math.ceil(v1 / K);
                ans = Math.max(ans, add);
                sum += p[i];
            }
            System.out.printf("%d\n", ans);
        }
    }
}
