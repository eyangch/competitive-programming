#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, A[200000], B[200000], X[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		for(int i = 0; i < N; i++){
			eat >> B[i];
		}
		eat >> M;
		multiset<int> rz;
		for(int i = 0; i < M; i++){
			eat >> X[i];
			rz.insert(X[i]);
		}
		set<int> active;
		bool ok = 1;
		for(int i = 0; i < N; i++){
			int a = A[i], b = B[i];
			if(a < b){
				ok = 0;
				break;
			}
			for(auto it = active.begin(); it != active.end();){
				if(*it < b){
					active.erase(it++);
				}else{
					break;
				}
			}
			if(a == b) continue;
			if(active.size() && *active.begin() == b){
				continue;
			}
			if(rz.find(b) == rz.end()){
				ok = 0;
				break;
			}
			active.insert(b);
			rz.erase(rz.find(b));
		}
		if(ok){
			moo << "YES" << endl;
		}else{
			moo << "NO" << endl;
		}
	}
}