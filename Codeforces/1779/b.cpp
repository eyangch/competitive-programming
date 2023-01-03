#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[2000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		if(N == 3){
			moo << "NO" << endl;
		}else{
			moo << "YES" << endl;
			if(N % 2 == 0){
				for(int i = 0; i < N/2; i++){
					moo << "-1 1 ";
				}
				moo << endl;
			}else{
				int a = N/2;
				int b = -(a-1);
				for(int i = 0; i < N; i++){
					if(i % 2 == 0){
						moo << b << ' ';
					}else{
						moo << a << ' ';
					}
				}
				moo << endl;
			}
		}
	}
}