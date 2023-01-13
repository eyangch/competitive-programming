#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, A, B, D;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> A >> B >> D;
		int lA = A&(-A);
		int lB = B&(-B);
		int lD = D&(-D);
		if(min(lA, lB) < lD){
			moo << -1 << endl;
			continue;kk
		}
		int X = D;
		int oD = D;
		int bit = 0;
		for(; ((D>>bit)&1) == 0; bit++);
		for(; bit < 30; bit++){
			if(((X>>bit) & 1) == 0){
				X += D;
			}
			D <<= 1;
		}
		assert((A|X)%oD == 0);
		assert((B|X)%oD == 0);
		moo << X << endl;
	}
}