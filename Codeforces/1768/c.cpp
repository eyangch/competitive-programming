#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000], P[200000], Q[200000], I[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i]--;
		}
		iota(I, I+N, 0);
		sort(I, I+N, [](int a, int b){
			return A[a] < A[b];
		});
		set<int> sp, sq;
		for(int i = 0; i < N; i++){
			sp.insert(i);
			sq.insert(i);
		}
		bool ok = 1;
		for(int _i = 0; _i < N; _i++){
			int i = I[_i];
			auto it1 = sp.find(A[i]);
			if(it1 != sp.end()){
				P[i] = *it1;
				Q[i] = *sq.begin();
				sp.erase(it1);
				sq.erase(sq.begin());
			}else{
				auto it2 = sq.find(A[i]);
				if(it2 == sq.end()){
					ok = 0;
					break;
				}
				P[i] = *sp.begin();
				Q[i] = *it2;
				sp.erase(sp.begin());
				sq.erase(it2);
			}
		}
		if(ok){
			moo << "yES" << endl;
			for(int i = 0; i < N; i++){
				moo << P[i]+1 << ' ';
			}
			moo << endl;
			for(int i = 0; i < N; i++){
				moo << Q[i]+1 << ' ';
			}
			moo << endl;
		}else{
			moo << "No" << endl;
		}
	}
}