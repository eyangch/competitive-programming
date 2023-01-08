#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, P[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K;
		for(int i = 0; i < N; i++){
			eat >> P[i];
			P[i]--;
		}
		int f = 0;
		for(int i = 0; i < N; i++){
			if(P[i] == f){
				f++;
			}
		}
		moo << (N-f+K-1)/K << endl;
	}
}