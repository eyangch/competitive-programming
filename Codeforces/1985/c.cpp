#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		set<int> p;
		int s = 0, ans = 0;
		for(int i = 0; i < N; i++){
			p.insert(A[i]*2);
			s += A[i];
			ans += p.count(s);
		}
		moo << ans << endl;
	}
}