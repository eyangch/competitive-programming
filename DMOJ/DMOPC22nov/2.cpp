#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[3000];
bool V[3000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
		A[i]--;
		V[A[i]] = 1;
	}
	bool ok = 1;
	for(int i = 0; i < N; i++){
		if(!V[i]) ok = 0;
	}
	if(!ok){
		moo << -1 << endl;
		return 0;
	}
	int swaps = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N-1; j++){
			if(A[j] > A[j+1]){
				swap(A[j], A[j+1]);
				swaps++;
			}
		}
	}
	moo << swaps << endl;
}