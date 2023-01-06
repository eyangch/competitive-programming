#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, D[250], I[250], ans[250];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		string q(N, '1');
		q[i] = '0';
		moo << "? " << i+1 << ' ' << q << endl;
		moo.flush();
		eat >> D[i];
	}
	iota(I, I+N, 0);
	sort(I, I+N, [](int a, int b){
		return D[a] > D[b];
	});
	int mx = 0;
	ans[I[0]] = 1;
	for(int i = 1; i < N; i++){
		string q(N, '0');
		for(int k = 0; k <= mx; k++){
			q[I[k]] = '1';
		}
		moo << "? " << I[i]+1 << ' ' << q << endl;
		moo.flush();
		int x; eat >> x;
		if(x){
			mx = i;
			for(int k = 0; k <= i; k++){
				ans[I[k]] = 1;
			}
		}
	}
	moo << "! ";
	for(int i = 0; i < N; i++){
		moo << ans[i];
	}
	moo << endl;
}