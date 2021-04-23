import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int N = Integer.parseInt(br.readLine());
        int p[] = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            p[i] = Integer.parseInt(st.nextToken());
        }
        int mat[][] = new int[N][N];
        for(int i = 0; i < N; i++) Arrays.fill(mat[i], -1);
        for(int i = 0; i < N; i++){
            int x = i, y = i;
            int nm = p[i];
            for(int j = 0; j < nm; j++){
                mat[x][y] = nm;
                if(y > 0 && mat[x][y-1] == -1){
                    y--;
                }else{
                    x++;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= i; j++){
                pw.print(mat[i][j] + " ");
            }
            pw.println();
        }
        br.close(); pw.close();
    }
}
