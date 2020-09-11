import java.util.*;

public class e {
	
	static boolean comp(String a, String b, char x, char y) {
		if((x == a.charAt(0) && y == a.charAt(1)) || (x == b.charAt(0) && y == b.charAt(1))) {
			return true;
		}
		return false;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		String s = in.next(), t = in.next();
		String perm[] = {"abc", "acb", "bac", "bca", "cab", "cba"};
		System.out.println("YES");
		if(s.charAt(0) == s.charAt(1) || t.charAt(0) == t.charAt(1)) {
			String good = null;
			for(String i : perm) {
				if(comp(s, t, i.charAt(0), i.charAt(1)) || comp(s, t, i.charAt(1), i.charAt(2)) || comp(s, t, i.charAt(2), i.charAt(0))) {
					continue;
				}
				good = i;
				break;
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < 3; j++) {
					System.out.print(good.charAt(j));
				}
			}
			System.out.println();
		}else {
			String good = null;
			for(String i : perm) {
				if(comp(s, t, i.charAt(0), i.charAt(1)) || comp(s, t, i.charAt(1), i.charAt(2))) {
					continue;
				}
				good = i;
				break;
			}
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < N; j++) {
					System.out.print(good.charAt(i));
				}
			}
			System.out.println();
		}
		in.close();
	}
}
