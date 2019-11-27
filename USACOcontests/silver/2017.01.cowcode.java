import java.io.*;
import java.util.*;

public class cowcode {
	static long log2(long x) {
		long i;
		for(i = 0; Math.pow(2, i) < x; i++) {}
		return i;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("cowcode.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("cowcode.out"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		String s = st.nextToken();
		long N = Long.parseLong(st.nextToken());
		int slen = s.length();
		while(N > slen) {
			long fold = log2((long)Math.ceil(N/(float)slen));
			if(N % (slen * Math.pow(2, fold-1)) == 1)
				N = slen * (long)Math.pow(2, fold-1);
			else
				N -= slen * (long)Math.pow(2, fold-1) + 1;
		}
		pw.println(s.charAt((int)(N-1)));
		br.close();
		pw.close();
	}
}
