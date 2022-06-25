#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> a[i];
		}
		int pv = -2, ans = 0;
		for(int i = 0; i < N; i++){
			if(a[i] == 0) pv = -2;
			else{
				if(pv == -2) ans++;
				pv = i;
			}
		}
		moo << min(2LL, ans) << endl;
	}
}