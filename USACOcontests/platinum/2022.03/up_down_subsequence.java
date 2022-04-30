import java.io.*;
import java.util.*;

public class up_down_subsequence{
    static BufferedReader br;
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int N, p[];
    static char s[];
    static ArrayList<Integer> sz;
    static int ans = 0;
    static int fis(int b, int l, int m){
        ArrayList<Integer> dp = new ArrayList<Integer>();
        for(int i = b; i < N; i++){
            int idx = ~Collections.binarySearch(dp, p[i] * m);
            if(idx == dp.size()){
                dp.add(p[i] * m);
                ans++;
            }
            else dp.set(idx, p[i] * m);
            if(dp.size() == l){
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) throws IOException{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = nextInt();
        p = new int[N];
        for(int i = 0; i < N; i++){
            p[i] = nextInt();
        }
        s = next().toCharArray();
        sz = new ArrayList<Integer>();
        ArrayList<Character> arc = new ArrayList<Character>();
        int prev = 0;
        for(int i = 1; i < N-1; i++){
            if(s[i] != s[i-1]){
                sz.add(i - prev);
                arc.add(s[i-1]);
                prev = i;
            }
        }
        sz.add(N-1 - prev);
        arc.add(s[N-2]);
        int cur = 0;
        for(int i = 0; i < sz.size(); i++){
            int nxt = fis(cur, sz.get(i)+1, (arc.get(i) == 'U' ? 1 : -1));
            ans--;
            if(nxt == -1){
                break;
            }
            cur = nxt;
        }
        pw.println(ans);
        br.close();
        pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int nextInt() throws IOException{
        return Integer.parseInt(next());
    }
}