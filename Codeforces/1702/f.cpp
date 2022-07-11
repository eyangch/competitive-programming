#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[200000], B[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		multiset<int> a;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			while(A[i] % 2 == 0){
				A[i] /= 2;
			}
			a.insert(A[i]);
		}
		for(int i = 0; i < N; i++){
			eat >> B[i];
		}
		bool good = 1;
		for(int i = 0; i < N; i++){
			good = 0;
			for(int j = 0; j < 32; j++){
				int nb = B[i] >> j;
				if(a.count(nb)){
					a.erase(a.find(nb));
					good = 1;
					break;
				}
			}
			if(!good){
				break;
			}
		}
		if(good) moo << "YES" << endl;
		else moo << "NO" << endl;
	}
}