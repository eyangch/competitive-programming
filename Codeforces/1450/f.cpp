#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100000], E[100000], O[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		fill(O, O+N, 0);
		for(int i = 0; i < N; i++){
			eat >> A[i];
			O[--A[i]]++;
		}
		fill(E, E+N, 0);
		E[A[0]]++;
		int ans = 0;
		for(int i = 0; i < N-1; i++){
			if(A[i] == A[i+1]) E[A[i]]++, E[A[i+1]]++, ans++;
		}
		E[A[N-1]]++;
		int mx1 = *max_element(E, E+N);
		int mx2 = *max_element(O, O+N);
		if(mx2 > N/2 + N%2) moo << -1 << endl;
		else moo << ans + max(0LL, mx1 - ans - 2) << endl;
	}
}