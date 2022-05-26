import java.io.*;
import java.util.*;

public class d{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(System.out);
    static StringTokenizer st = new StringTokenizer("");
    static int T, A, B, C, D, N;
    static char[] s;
    public static void main(String args[]) throws IOException{
        T = nextInt();
        while(T-- > 0){
            A = nextInt();
            B = nextInt();
            C = nextInt();
            D = nextInt();
            s = next().toCharArray();
            N = s.length;
            int nA = 0, nB = 0;
            for(int i = 0; i < N; i++){
                if(s[i] == 'A') nA++;
                if(s[i] == 'B') nB++;
            }
            if(nA != A + C + D || nB != B + C + D){
                pw.println("nO");
                continue;
            }
            ArrayList<Integer> n[] = new ArrayList[3];
            for(int i = 0; i < 3; i++) n[i] = new ArrayList<Integer>();
            for(int i = 0; i < N; i++){
                int cur = i;
                while(++cur < N){
                    if(s[cur] == s[cur-1]){
                        break;
                    }
                }
                if(s[i] == 'A' && s[cur-1] == 'B'){
                    n[0].add(cur-i);
                }
                if(s[i] == s[cur-1]){
                    n[1].add(cur-i);
                }
                if(s[i] == 'B' && s[cur-1] == 'A'){
                    n[2].add(cur-i);
                }
                i = cur-1;
            }
            Collections.sort(n[0]);
            Collections.sort(n[2], Collections.reverseOrder());
            for(int i = 0; i < n[0].size(); i++){
                if(C > 0){
                    int nABs = Math.min(C, n[0].get(i)/2);
                    C -= nABs;
                    n[0].set(i, n[0].get(i) - nABs*2);
                }
                if(C == 0){
                    int nBAs = Math.max(0, n[0].get(i)/2-1);
                    D -= nBAs;
                }
            }
            for(int i = 0; i < n[1].size(); i++){
                if(C > 0){
                    int nABs = Math.min(C, n[1].get(i)/2);
                    C -= nABs;
                    n[1].set(i, n[1].get(i) - nABs * 2);
                }
                if(C == 0){
                    int nBAs = n[1].get(i)/2;
                    D -= nBAs;
                }
            }
            for(int i = 0; i < n[2].size(); i++){
                if(C > 0){
                    n[2].set(i, n[2].get(i) - 1);
                    int nABs = Math.min(C, n[2].get(i)/2);
                    C -= nABs;
                    n[2].set(i, n[2].get(i) - nABs * 2);
                }
                if(C == 0){
                    int nBAs = n[2].get(i)/2;
                    D -= nBAs;
                }
            }
            if(C > 0 || D > 0){
                pw.println("No");
            }else{
                pw.println("yES");
            }
        }
        br.close(); pw.close();
    }
    static String next() throws IOException{
        while(!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int nextInt() throws IOException{
        return Integer.parseInt(next());
    }
}

