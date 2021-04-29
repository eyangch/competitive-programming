import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static int T, N, M, K;
    static HashSet<Integer> ar[][];
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        ar = new HashSet[100][100];
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                ar[i][j] = new HashSet<Integer>();
            }
        }
        ar[0][0].add(0);
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                int x = i+1, y = j;
                if(x < 100){
                    for(int k : ar[i][j]){
                        ar[x][y].add(k + y+1);
                    }
                }
                x = i;
                y = j+1;
                if(y < 100){
                    for(int k : ar[i][j]){
                        ar[x][y].add(k + x+1);
                    }
                }
            }
        }
        T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            pw.println((ar[N-1][M-1].contains(K) ? "YES" : "NO"));
        }
        br.close(); pw.close();
    }
}
