import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static int N, K;
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        StringBuilder ans = new StringBuilder(N);
        ans.append('a');
        N--;
        while(N > 0){
            for(int i = 1; N > 0 && i < K-1; i++){
                ans.append((char)('a' + i));
                N--;
            }
            for(int i = K-1; i >= 0 && N > 0; i--){
                ans.append((char)('a' + i));
                N--;
                if(N == 0) break;
                ans.append((char)('a' + i));
                N--;
                for(int j = 0; j < i-1 && N > 0; j++){
                    ans.append((char)('a' + j));
                    N--;
                    if(N == 0) break;
                    ans.append((char)('a' + i));
                    N--;
                }
            }
        }
        pw.println(ans);
        br.close(); pw.close();    
    }
}
