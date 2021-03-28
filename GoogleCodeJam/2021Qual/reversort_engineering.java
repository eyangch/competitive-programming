import java.io.*;
import java.util.*;

public class Solution{
    static int T, N, C, ar[];
    static String s;
    static void reverse(int i, int j){
        while(i < j){
            int tmp = ar[i];
            ar[i] = ar[j];
            ar[j] = tmp;
            i++;
            j--;
        }
    }
    public static void main(String args[]) throws IOException{
        BufferedReader eat = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter moo = new PrintWriter(System.out);
        T = Integer.parseInt(eat.readLine());
        for(int tc = 1; tc <= T; tc++){
            moo.print("Case #" + tc + ": ");
            StringTokenizer st = new StringTokenizer(eat.readLine());
            N = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());
            int amt = N-1;
            if(C < amt){
                moo.println("IMPOSSIBLE");
                continue;
            }
            ar = new int[N];
            for(int i = 0; i < N; i++) ar[i] = i;
            ArrayList<Integer> s = new ArrayList<Integer>();
            ArrayList<Integer> e = new ArrayList<Integer>();
            for(int i = 0; i < N-1; i++){
                if(amt + N-1- i >= C){
                    int gap = C-amt;
                    s.add(i);
                    e.add(i+gap);
                    amt = C;
                    break;
                }else{
                    s.add(i);
                    e.add(N-1);
                    amt += N-1-i;
                }
            }
            for(int i = s.size()-1; i >= 0; i--){
                reverse(s.get(i), e.get(i));
            }
            if(amt != C){
                moo.println("IMPOSSIBLE");
                continue;
            }
            for(int i = 0; i < N; i++){
                moo.print(ar[i] + 1 + " ");
            }
            moo.println();
        }
        eat.close(); moo.close();
    }
}
