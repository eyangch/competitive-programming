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
		for(int i = 1; i <= 1e9; i++){
			if(N % i != 0){
				for(int j = 0; j < N; j++){
					moo << (char)('a'+(j%(i)));
				}
				moo << endl;
				break;
			}
		}
	}
}