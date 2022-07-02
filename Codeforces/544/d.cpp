#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, S1, T1, L1, S2, T2, L2;
vector<int> graph[3000];
int D[3000][3000];

void bfs(int src){
	queue<int> q;
	q.push(src);
	fill(D[src], D[src]+N, -1);
	D[src][src] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i : graph[v]){
			if(~D[src][i]) continue;
			D[src][i] = D[src][v] + 1;
			q.push(i);
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	for(int i = 0; i < M; i++){
		int u, v; eat >> u >> v;
		graph[u-1].push_back(v-1);
		graph[v-1].push_back(u-1);
	}
	eat >> S1 >> T1 >> L1 >> S2 >> T2 >> L2;
	S1--, T1--, S2--, T2--;
	for(int i = 0; i < N; i++){
		bfs(i);
	}
	if(D[S1][T1] > L1 || D[S2][T2] > L2){
		moo << -1 << endl;
		return 0;
	}
	int rem = D[S1][T1] + D[S2][T2];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < 2; k++){
				int d1 = D[S1][i] + D[i][j] + D[j][T1];
				int d2 = D[S2][i] + D[i][j] + D[j][T2];
				if(d1 <= L1 && d2 <= L2){
					rem = min(rem, D[S1][i] + D[S2][i] + D[i][j] + D[j][T1] + D[j][T2]);
				}
				swap(S2, T2);
			}
		}
	}
	moo << M - rem << endl;
}