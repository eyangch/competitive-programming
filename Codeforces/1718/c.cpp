#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, Q, A[200000], offset[10][200000];
bool sieve[200001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> Q;
		fill(sieve, sieve+N+1, 0);
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		vector<int> pf;
		for(int i = 2; i <= N; i++){
			if(sieve[i]) continue;
			for(int j = i; j <= N; j += i){
				sieve[j] = 1;
				if(j == N){
					pf.push_back(i);
				}
			}
		}
		for(int i = 0; i < (int)pf.size(); i++){
			for(int j = 0; j < N; j++){
				offset[i][j] = 0;
			}
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < (int)pf.size(); j++){
				offset[j][i % (N/pf[j])] += A[i] * (N/pf[j]);
			}
		}
		multiset<int> ms;
		for(int i = 0; i < (int)pf.size(); i++){
			for(int j = 0; j < N/pf[i]; j++){
				ms.insert(offset[i][j]);
			}
		}
		moo << *ms.rbegin() << endl;
		/*moo << "PF: ";
		for(int i : pf){
			moo << i << ' ';
		}
		moo << endl;*/
		for(int i = 0; i < Q; i++){
			int p, x; eat >> p >> x;
			p--;
			for(int j = 0; j < (int)pf.size(); j++){
				int &cur = offset[j][p % (N/pf[j])];
				ms.erase(ms.find(cur));
				cur -= A[p] * (N/pf[j]);
				cur += x * (N/pf[j]);
				ms.insert(cur);
			}
			A[p] = x;
			moo << *ms.rbegin() << endl;
		}
	}
}