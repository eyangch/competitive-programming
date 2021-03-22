import java.io.*;
import java.util.*;

public class d{
    public static void main(String args[]) throws IOException{
        BufferedReader eat = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter moo = new PrintWriter(System.out);
        int T = Integer.parseInt(eat.readLine());
        int pf[] = new int[20000001];
        for(int i = 2; i <= 20000000; i++){
            if(pf[i] == 0){
                for(int j = i; j <= 20000000; j += i){
                    pf[j]++;
                }
            }
        }
        long p2[] = new long[60];
        p2[0] = 1;
        for(int i = 1; i < 60; i++){
            p2[i] = p2[i-1] << 1;
        }
        while(T-- > 0){
            long ans = 0;
            StringTokenizer st = new StringTokenizer(eat.readLine());
            int c = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken()), x = Integer.parseInt(st.nextToken());
            for(int i = 1; i * i <= x; i++){
                if(x % i != 0) continue;
                int cur = x/i + d;
                if(cur % c != 0) continue;
                cur /= c;
                ans += p2[pf[cur]];
            }
            for(int i = 1; i * i < x; i++){
                if(x % i != 0) continue;
                int cur = i + d;
                if(cur % c != 0) continue;
                cur /= c;
                ans += p2[pf[cur]];
            }
            moo.println(ans);
        }
        eat.close(); moo.close();
    }
}
