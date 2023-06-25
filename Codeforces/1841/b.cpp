#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, Q, X[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> Q;
		for(int i = 0; i < Q; i++){
			eat >> X[i];
		}
		bool dropped = 0;
		int first = X[0], last = 0;
		for(int i = 0; i < Q; i++){
			bool ok = 1;
			if(dropped){
				if(X[i] < last) ok = 0;
				else if(X[i] > first) ok = 0;
				else last = X[i];
			}else{
				if(X[i] < last){
					if(X[i] > first) ok = 0;
					else last = X[i], dropped = 1;
				}else{
					last = X[i];
				}
			}
			moo << ok;
		}
		moo << endl;
	}
}