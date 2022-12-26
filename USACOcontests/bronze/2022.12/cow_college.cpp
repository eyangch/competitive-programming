#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, C[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> C[i];
	}
	sort(C, C+N);
	int ans = 0, ansi = 0;
	for(int i = 0; i < N; i++){
		int cur = (N-i) * C[i];
		if(cur > ans) ans = cur, ansi = C[i];
	}
	moo << ans << ' ' << ansi << endl;
}