import java.io.*;
import java.util.*;

public class Solution{
    static int T, N, Q;
    static BufferedReader eat;
    static PrintWriter moo;
    static int qry(int a, int b, int c) throws IOException{
        moo.println(a + " " + b + " " + c);
        moo.flush();
        int res = Integer.parseInt(eat.readLine());
        return res;
    }
    public static void main(String args[]) throws IOException{
        eat = new BufferedReader(new InputStreamReader(System.in));
        moo = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(eat.readLine());
        T = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());
        for(int tc = 1; tc <= T; tc++){
            ArrayList<Integer> ord = new ArrayList<Integer>();
            ord.add(1); ord.add(2);
            for(int i = 3; i <= N; i++){
                int lo = -1, hi = ord.size();
                while(lo + 1 < hi){
                    int m1 = Math.max(0, lo + (hi - lo) / 3);
                    int m2 = Math.min(ord.size()-1, hi - (hi - lo + 2) / 3);
                    if(m1 == m2) m2++;
                    int x = qry(ord.get(m1), ord.get(m2), i);
                    if(x == ord.get(m1)){
                        hi = m1;
                    }
                    if(x == ord.get(m2)){
                        lo = m2;
                    }
                    if(x == i){
                        hi = m2;
                        lo = m1;
                    }
                }
                ord.add(lo+1, i);
            }
            for(int i : ord){
                moo.print(i + " ");
            }
            moo.println();
            moo.flush();
            int status = Integer.parseInt(eat.readLine());
            assert status != -1;
        }
        eat.close(); moo.close();
    }
}
