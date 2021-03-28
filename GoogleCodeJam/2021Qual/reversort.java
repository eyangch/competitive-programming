import java.io.*;
import java.util.*;

public class Solution{
    static int T, N, L[];
    static void reverse(int i, int j){
        while(i < j){
            int tmp = L[i];
            L[i] = L[j];
            L[j] = tmp;
            i++;
            j--;
        }
    }
    static int reversort(){
        int ans = 0;
        for(int i = 0; i < N-1; i++){
            int mx = N+1, mxidx = 0;
            for(int j = i; j < N; j++){
                if(L[j] < mx){
                    mx = L[j];
                    mxidx = j;
                }
            }
            reverse(i, mxidx);
            ans += mxidx - i + 1;
        }
        return ans;
    }
    public static void main(String args[]) throws IOException{
        BufferedReader eat = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter moo = new PrintWriter(System.out);
        T = Integer.parseInt(eat.readLine());
        for(int tc = 1; tc <= T; tc++){
            moo.print("Case #" + tc + ": ");
            N = Integer.parseInt(eat.readLine());
            L = new int[N];
            StringTokenizer st = new StringTokenizer(eat.readLine());
            for(int i = 0; i < N; i++){
                L[i] = Integer.parseInt(st.nextToken());
            }
            moo.println(reversort());
        }
        eat.close(); moo.close();
    }
}
