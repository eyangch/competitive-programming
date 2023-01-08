#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, P[200000];
bool vis[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> P[i];
			P[i]--;
		}
		int ans = 1;
		bool f = 0;
		fill(vis, vis+N, 0);
		for(int i = 0; i < N; i++){
			if(vis[i]) continue;
			int sz = 0;
			int cur = i;
			set<int> cv;
			while(!vis[cur]){
				cv.insert(cur);
				sz++;
				vis[cur] = 1;
				if(cv.count(cur-1) || cv.count(cur+1)){
					f = 1;
				}
				cur = P[cur];
			}
			ans += sz-1;
		}
		moo << ans - 2*f << endl;
	}
}