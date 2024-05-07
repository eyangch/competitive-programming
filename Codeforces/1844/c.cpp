#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, C[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> C[i];
		}
		int sm = 0, mx = *max_element(C, C+N);
		for(int i = 0; i < N; i += 2){
			if(C[i] > 0) sm += C[i];
		}
		if(sm > 0) mx = max(mx, sm);
		sm = 0;
		for(int i = 1; i < N; i += 2){
			if(C[i] > 0) sm += C[i];
		}
		if(sm > 0) mx = max(mx, sm);
		moo << mx << endl;
	}
}