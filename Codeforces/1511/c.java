import java.io.*;
import java.util.*;

public class a{
    static BufferedReader br;
    static PrintWriter pw;
    static int N, Q, fc[];
    public static void main(String args[]) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        fc = new int[50];
        Arrays.fill(fc, -1);
        for(int i = 0; i < N; i++){
            int x = Integer.parseInt(st.nextToken());
            if(fc[x-1] == -1){
                fc[x-1] = i;
            }
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < Q; i++){
            int t = Integer.parseInt(st.nextToken())-1;
            pw.print(fc[t] + 1 + " ");
            for(int j = 0; j < 50; j++){
                if(fc[j] < fc[t]) fc[j]++;
            }
            fc[t] = 0;
        }
        pw.println();
        br.close(); pw.close();    
    }
}
