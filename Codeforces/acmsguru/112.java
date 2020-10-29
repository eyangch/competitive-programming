import java.io.*;
import java.util.*;
import java.math.*;

public final class acmsguru112{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        BigInteger a1 = BigInteger.valueOf(a), b1 = BigInteger.valueOf(b);
        BigInteger ans = a1.pow(b).subtract(b1.pow(a));
        System.out.println(ans);
    }
}
