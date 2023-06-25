#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, X;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> X;
		int a = 0, b = 0, S = 2*X;
		int c = 0;
		for(int i = 30; i >= 0; i--){
			int xb = (X>>i)&1, sb = (S>>i)&1;
			if(xb){
				a |= (1<<i);
			}else{
				if(c) a |= (1<<i), b |= (1<<i);
			}
			if(xb != sb) c = 1;
			else c = 0;
		}
		if(2*(a^b) == a+b && a+b == S){
			moo << a << ' ' << b << endl;
		}else{
			moo << -1 << endl;
		}
	}
}