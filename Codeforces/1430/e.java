import java.io.*;
import java.util.*;
import java.math.*;

public final class e{
    
    static int N;
    static String s;
    static long BIT[];
    
    static long get(int x){
        int sum = 0;
        for(; x > 0; x -= x&-x){
            sum += BIT[x];
        }
        return sum;
    }

    static void upd(int x, int dv){
        for(; x <= N; x += x&-x){
            BIT[x] += dv;
        }
    }

    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        s = br.readLine();
        Queue<Integer> letters[] = new Queue[26];
        for(int i = 0; i < 26; i++){
            letters[i] = new LinkedList<Integer>();
        }
        for(int i = 0; i < N; i++){
            letters[s.charAt(i)-'a'].add(i);
        }
        long ans = 0;
        BIT = new long[300000];
        for(int i = 0; i < N; i++){
            int nxt = letters[s.charAt(N-i-1)-'a'].poll();
            ans += Math.abs(nxt+(get(N) - get(nxt+1)) - i);
            upd(nxt+1, 1);
        }
        System.out.println(ans);
    }
}
