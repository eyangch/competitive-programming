import java.io.*;
import java.util.*;

public final class a{
    static int N, x[], y[];
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        N = Integer.parseInt(in.readLine());
        x = new int[N];
        y = new int[N];
        StringTokenizer st = new StringTokenizer(in.readLine());
        for(int i = 0; i < N; i++){
            x[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(in.readLine());
        for(int i = 0; i < N; i++){
            y[i] = Integer.parseInt(st.nextToken());
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                ans = Math.max(ans, (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
            }
        }
        out.println(ans);
        in.close();
        out.close();
    }
}
