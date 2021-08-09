import java.io.*;
import java.util.*;

public class Program{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T, N, K, a[];
    public static void main(String args[]) throws IOException{
        T = nexti();
        while(T-- > 0){
            N = nexti();
            K = nexti();
            a = new int[N];
            for(int i = 0; i < N; i++){
                a[i] = nexti();
            }
            Integer a2[] = new Integer[N];
            for(int i = 0; i < N; i++) a2[i] = a[i];
            Arrays.sort(a2);
            HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
            for(int i = 0; i < N; i++){
                hm.put(a2[i], i);
            }
            int used = 1;
            int prev = hm.get(a[0]);
            for(int i = 1; i < N; i++){
                if(hm.get(a[i]) != prev+1){
                    prev = hm.get(a[i]);
                    used++;
                }else{
                    prev++;
                }
            }
            pw.println((used <= K ? "YeS" : "nO"));
        }
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int nexti() throws IOException{
        return Integer.parseInt(next());
    }
}

