#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, P[100001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = N; i >= 1; i-=2){
			P[i] = i-1;
			P[i-1] = i;
		}
		if(N % 2 == 1){
			P[1] = 1;
		}
		for(int i = 1; i <= N; i++){
			moo << P[i] << ' ';
		}
		moo << endl;
	}
}