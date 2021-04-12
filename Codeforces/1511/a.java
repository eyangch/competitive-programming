import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static int T, N, r[];
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            r = new int[N];
            int ans = 0;
            for(int i = 0; i < N; i++){
                r[i] = Integer.parseInt(st.nextToken());
                if(r[i] == 1 || r[i] == 3) ans++;
            }
            pw.println(ans);
        }
        br.close(); pw.close();    
    }
}
