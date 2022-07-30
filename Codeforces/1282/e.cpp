#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, S[100000][3], in[100000];
bool out[100000][3];
pair<int, int> RAW[100000][3];
vector<int> link[300000], adj[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N-2; i++){
			link[3*i].clear(), link[3*i+1].clear(), link[3*i+2].clear();
			in[i] = 0;
			fill(out[i], out[i]+3, 0);
			adj[3*i].clear(), adj[3*i+1].clear(), adj[3*i+2].clear();
		}
		vector<pair<int, int>> sides;
		for(int i = 0; i < N-2; i++){
			int a, b, c; eat >> a >> b >> c;
			a--, b--, c--;
			pair<int, int> p1 = {a, b}, p2 = {b, c}, p3 = {c, a};
			if(p1.first > p1.second) swap(p1.first, p1.second);
			if(p2.first > p2.second) swap(p2.first, p2.second);
			if(p3.first > p3.second) swap(p3.first, p3.second);
			RAW[i][0] = p1, RAW[i][1] = p2, RAW[i][2] = p3;
			sides.push_back(p1), sides.push_back(p2), sides.push_back(p3);
		}
		sort(sides.begin(), sides.end());
		int lst = unique(sides.begin(), sides.end()) - sides.begin();
		for(int i = 0; i < N-2; i++){
			for(int j = 0; j < 3; j++){
				int a = lower_bound(sides.begin(), sides.begin()+lst, RAW[i][j]) - sides.begin();
				S[i][j] = a;
				link[a].push_back(i);
			}
		}
		for(int i = 0; i < N-2; i++){
			for(int j = 0; j < 3; j++){
				if((int)link[S[i][j]].size() > 1){
					in[i]++;
				}else{
					out[i][j] = 1;
					adj[RAW[i][j].first].push_back(RAW[i][j].second);
					adj[RAW[i][j].second].push_back(RAW[i][j].first);
				}
			}
		}
		vector<int> P;
		int p = -1, c = 0;
		for(int i = 0; i < N; i++){
			//moo << i << ' ' ;
			//for(int j : adj[i]) moo << j << ' ';
			//moo << endl;
			P.push_back(c+1);
			for(int j : adj[c]){
				if(j == p) continue;
				p = c;
				c = j;
				break;
			}
		}
		queue<int> q;
		for(int i = 0; i < N-2; i++){
			if(in[i] <= 1) q.push(i);
		}
		vector<int> Q;
		while(!q.empty()){
			int i = q.front();
			q.pop();
			Q.push_back(i+1);
			for(int j = 0; j < 3; j++){
				int a = S[i][j];
				for(int k : link[a]){
					if(--in[k] == 1) q.push(k);
				}
			}
		}
		for(int i : P){
			moo << i << ' ';
		}
		moo << endl;
		for(int i : Q){
			moo << i << ' ';
		}
		moo << endl;
	}
}