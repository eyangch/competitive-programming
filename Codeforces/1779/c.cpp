#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, A[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		M--;
		multiset<int> S;
		int sum = 0;
		int op = 0;
		for(int i = M; i > 0; i--){
			S.insert(-A[i]);
			sum += -A[i];
			if(sum < 0){
				auto it = S.begin();
				int x = -2 * (*it);
				sum += x;
				S.erase(it);
				op++;
			}
		}
		sum = 0;
		S.clear();
		for(int i = M+1; i < N; i++){
			S.insert(A[i]);
			sum += A[i];
			if(sum < 0){
				auto it = S.begin();
				int x = -2 * (*it);
				sum += x;
				S.erase(it);
				op++;
			}
		}
		moo << op << endl;
	}
}