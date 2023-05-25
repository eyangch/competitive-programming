import java.io.*;
import java.util.*;

public class c{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	static StringTokenizer st = new StringTokenizer("");
	public static void main(String[] args) throws IOException{
		long R = nextInt(), x1 = nextInt(), y1 = nextInt(), x2 = nextInt(), y2 = nextInt();
		x2 -= x1; y2 -= y1;
		if(x2 * x2 + y2 * y2 > R * R){
			pw.println(x1 + " " + y1 + " " + R);
		}else if(x2 == 0 && y2 == 0){
			pw.println(x1 + R/2.0 + " " + y1 + " " + R / 2.0);
		}else{
			double x3 = -x2 / Math.sqrt(y2 * y2 + x2 * x2) * R;
			double y3 = -y2 / Math.sqrt(y2 * y2 + x2 * x2) * R;
			double x = (x3 + x2) / 2, y = (y3 + y2) / 2;
			double r = Math.sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
			pw.println(x + x1 + " " + (y + y1) + " " + r);
		}
		br.close(); pw.close();
	}
	static String next() throws IOException{
		while(!st.hasMoreTokens()){
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
	static long nextInt() throws IOException{
		return Integer.parseInt(next());
	}
}
