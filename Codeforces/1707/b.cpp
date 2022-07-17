#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100000];
map<int, int> m[2];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		m[0].clear();
		m[1].clear();
		for(int i = 0;i < N; i++){
			eat >> A[i];
			m[0][A[i]]++;
		}
		int lstnxt = 0;
		for(int i = 0; i < N-1; i++){
			int nxt = !(i & 1);
			int cur = (i & 1);
			int pv = -1;
			lstnxt = nxt;
			for(pair<int, int> j : m[cur]){
				if(j.second > 1) m[nxt][0] += j.second-1;
				if(pv != -1) m[nxt][j.first-pv]++;
				pv = j.first;
			}
			m[cur].clear();
		}
		moo << (m[lstnxt].begin()->first) << endl;
	}
}