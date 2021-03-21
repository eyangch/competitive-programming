import java.io.*;
import java.util.*;

public class f{

    static int N, a[], occ[];

    public static void main(String args[]) throws IOException{
        BufferedReader eat = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter moo = new PrintWriter(System.out);
        N = Integer.parseInt(eat.readLine());
        a = new int[N];
        occ = new int[200000];
        StringTokenizer st = new StringTokenizer(eat.readLine());
        for(int i = 0; i < N; i++){
            a[i] = Integer.parseInt(st.nextToken()) - 1;
            occ[a[i]]++;
        }
        int mx = 0, l = 0, r = 0;
        int cur = 0, prev = 0;
        for(int i = 0; i < 200000; i++){
            if(occ[i] == 0){
                if(cur > mx){
                    mx = cur;
                    l = prev;
                    r = i;
                }
                prev = i+1;
                cur = 0;
            }else if(occ[i] == 1){
                cur += occ[i];
                if(cur > mx){
                    mx = cur;
                    l = prev;
                    r = i+1;
                }
                prev = i;
                cur = occ[i];
            }else{
                cur += occ[i];
                if(cur > mx){
                    mx = cur;
                    l = prev;
                    r = i+1;
                }
            }
        }
        moo.println(mx);
        for(int i = l; i < r; i++){
            moo.print(i+1 + " ");
        }
        for(int i = r-1; i >= l; i--){
            while(--occ[i] > 0){
                moo.print(i+1 + " ");
            }
        }
        moo.println();
        eat.close();
        moo.close();
    }
}
