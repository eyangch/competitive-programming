#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		int cur = 1;
		int add = -1;
		for(int i = 0; i < N; i++){
			int x; eat >> x;
			cur *= x;
			add++;
		}
		moo << (cur + add) * 2022 << endl;
	}
}