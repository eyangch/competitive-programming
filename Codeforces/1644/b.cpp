#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[50];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			A[i] = N-i;
		}
		for(int i = 0; i < N; i++){
			if(i > 0) swap(A[i], A[i-1]);
			for(int j= 0; j < N; j++){
				moo << A[j] << ' ';
			}
			if( i > 0) swap(A[i], A[i-1]);
			moo << endl;
			
		}
	}
}