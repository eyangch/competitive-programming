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
		bool f1 = 0;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			if(A[i] == 1) f1 = 1;
		}
		if(!f1){
			moo << 0 << endl;
			continue;
		}
		queue<int> q0, q1;
		for(int i = N-1; i >= 0; i--){
			if(A[i] == 0) q0.push(i);
		}
		for(int i = 0; i < N; i++){
			if(A[i] == 1) q1.push(i);
		}
		int ops = 0;
		while(true){
			if(q0.empty() || q1.empty()) break;
			int a = q0.front(), b = q1.front();
			if(b > a) break;
			q0.pop();
			q1.pop();
			ops++;
		}
		moo << ops << endl;
	}
}