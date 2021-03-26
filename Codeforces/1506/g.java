import java.io.*;
import java.util.*;

public class g{
    static int T;
    static String s;
    public static void main(String args[]) throws IOException{
        BufferedReader eat = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter moo = new PrintWriter(System.out);
        T = Integer.parseInt(eat.readLine());
        while(T-- > 0){
            s = eat.readLine();
            String ans = "";
            TreeSet<Character> ts = new TreeSet<Character>();
            int fst[] = new int[128], lst[] = new int[128];
            for(int i = 0; i < s.length(); i++){
                ts.add(s.charAt(i));
            }
            int len = ts.size();
            int lb = 0;
            for(int i = 0; i < len; i++){
                Iterator<Character> it = ts.descendingIterator();
                Arrays.fill(fst, -1);
                for(int j = lb; j < s.length(); j++){
                    if(fst[s.charAt(j)] == -1) fst[s.charAt(j)] = j;
                    lst[s.charAt(j)] = j;
                }
                while(it.hasNext()){
                    char cur = it.next();
                    boolean f = false;
                    for(int j : ts){
                        if(lst[j] < fst[cur]){
                            f = true;
                            break;
                        }
                    }
                    if(f) continue;
                    ans += cur;
                    lb = fst[cur];
                    it.remove();
                    break;
                }
            }
            moo.println(ans);
        }
        eat.close(); moo.close();
    }
}
