import java.io.*;
import java.util.*;

public class d{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");
	static int fib[];
	static boolean solve(int w, int h, int x, int y, int f){
		//pw.println(w + " " + h + " " + x + " " + y + " " + f);
		if(f == 1) return true;
		if(x <= fib[f-1]){
			return solve(h, w-fib[f], y, x, f-1);
		}else if(x > fib[f]){
			return solve(h, w-fib[f], y, x-fib[f], f-1);
		}else{
			return false;
		}
	}
	public static void main(String[] args) throws IOException{
		int T = nextInt();
		fib = new int[50];
		fib[0] = 1; fib[1] = 1;
		for(int i = 2; i < 50; i++){
			fib[i] = fib[i-1] + fib[i-2];
		}
		while(T --> 0){
			int N = nextInt(), X = nextInt(), Y = nextInt();
			if(solve(fib[N+1], fib[N], Y, X, N)){
				pw.println("yES");
			}else{
				pw.println("nO");
			}
		}
		br.close(); pw.close();
	}
	static String next() throws IOException{
		while(!st.hasMoreTokens()){
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
	static int nextInt() throws IOException{
		return Integer.parseInt(next());
	}
}