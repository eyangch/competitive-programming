import java.io.*;
import java.util.*;

public final class b{
    static int N, X, a[];
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(in.readLine());
        N = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        a = new int[N];
        st = new StringTokenizer(in.readLine());
        for(int i = 0; i < N; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(a);
        int ans = 0, sum = 0;
        for(int i = 0; i < N; i++){
            if(sum + a[i] > X) break;
            sum += a[i];
            ans++;
        }
        out.println(ans);
        in.close();
        out.close();
    }
}

