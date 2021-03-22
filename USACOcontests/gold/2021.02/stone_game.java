import java.io.*;
import java.util.*;

public class stone_game{

    static int N, a[], occ[];

    public static void main(String args[]) throws IOException{
        BufferedReader eat = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter moo = new PrintWriter(System.out);
        N = Integer.parseInt(eat.readLine());
        a = new int[N];
        occ = new int[2000001];
        StringTokenizer st = new StringTokenizer(eat.readLine());
        for(int i = 0; i < N; i++){
            a[i] = Integer.parseInt(st.nextToken());
            occ[a[i]]++;
        }
        for(int i = 1; i <= 2000000; i++){
            occ[i] += occ[i-1];
        }
        long ans = 0;
        for(int i = 1; i <= 1000000; i++){
            int odd[] = new int[2];
            int cur = i;
            while(cur <= 1000000){
                int rn = occ[cur+i-1] - occ[cur-1];
                if(rn % 2 == 1){
                    if(odd[0] > 0) odd[1] = cur/i;
                    else odd[0] = cur/i;
                }
                cur += i;
            }
            if(odd[1] > 0 && odd[0] + 1 == odd[1]){
                ans += occ[odd[1] * i + i-1] - occ[odd[1] * i - 1];
            }
            if(odd[1] == 0 && odd[0] == 1){
                ans += occ[i + i-1] - occ[i-1];
            }
        }
        moo.println(ans);
        eat.close();
        moo.close();
    }
}
