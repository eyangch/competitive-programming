import java.io.*;
import java.util.*;

public class f{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws IOException{
		int N = Integer.parseInt(br.readLine());
		int A[][] = new int[N][26];
		int X[] = new int[N];
		for(int i = 0; i < N; i++){
			char[] s = br.readLine().toCharArray();
			for(char c : s){
				A[i][c-'a']++;
			}
			for(int j = 0; j < 26; j++){
				if(A[i][j] % 2 == 1){
					X[i] |= (1<<j);
				}
			}
		}
		long ans = 0;
		for(int i = 0; i < 26; i++){
			HashMap<Integer, Integer> hm = new HashMap<>();
			for(int j = 0; j < N; j++){
				if(A[j][i] == 0){
					int cur = X[j] & (((1<<26)-1) ^ (1<<i));
					int flip = (~X[j]) & (((1<<26)-1) ^ (1<<i));
					if(hm.containsKey(flip)){
						ans += hm.get(flip);
					}
					if(hm.containsKey(cur)){
						hm.put(cur, hm.get(cur)+1);
					}else{
						hm.put(cur, 1);
					}
				}
			}
		}
		System.out.println(ans);
		br.close();
	}
}
