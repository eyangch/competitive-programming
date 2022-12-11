#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, L, A[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> L;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	int x = 1e15;
	for(int i = 0; i < N; i++){
		auto it = lower_bound(A, A+N, L-A[i]);
		if(it != A+N){
			x = min(x, *it - (L-A[i]));
		}
		if(it != A){
			it--;
			x = min(x, L-A[i]-*it);
		}
	}
	moo << 2 * (L + x) << endl;
}