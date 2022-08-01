#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		bool tl = 0, fl = 0;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			if(A[i] % 10 == 0 || A[i] % 10 == 5) fl = 1;
			else tl = 1;
			if(A[i] % 2 == 1){
				A[i] += A[i] % 10;
			}
		}
		if(fl && tl){
			moo << "No" << endl;
			continue;
		}
		if(fl){
			for(int i = 0; i < N; i++){
				if(A[i] % 10 == 5) A[i] += 5;
			}
			bool ok = 1;
			for(int i = 1; i < N; i++){
				if(A[i] != A[i-1]) ok = 0;
			}
			if(ok) moo << "Yes" << endl;
			else moo << "No" << endl;
			continue;
		}
		for(int i = 0; i < N; i++){
			if(A[i] % 10 == 6){
				A[i] += 10;
			}
			A[i] /= 10;
		}
		bool good = 1;
		for(int i = 1; i < N; i++){
			if(A[i] % 2 != A[i-1] % 2){
				good = 0;
				break;
			}
		}
		if(good) moo << "Yes" << endl;
		else moo << "No" << endl;
	}
}