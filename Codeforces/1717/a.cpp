#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		int ans = 0;
		int f3 = N / 3;
		int f2 = N / 2;
		int f1 = N;
		f1 -= f2;
		f2 -= f3;
		ans += f3 * 5 + f2 * 3 + f1;
		moo << ans << endl;
	}
}