#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M;
vector<string> S;
int ans = 0;
bool vis[1000][1000];

void aux(int x, int y, int dx, int dy){
	int mx = -1;
	for(; x >= 0 && y >= 0 && x < N && y < M; x += dx, y += dy){
		if(S[x][y] - '0' > mx) vis[x][y] = 1;
		mx = max(mx, (int)S[x][y] - '0');
	}
}

void part1(){
	for(int i = 0; i < N; i++){
		aux(i, 0, 0, 1);
		aux(i, M-1, 0, -1);
	}
	for(int i = 0; i < M; i++){
		aux(0, i, 1, 0);
		aux(N-1, i, -1, 0);
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(vis[i][j]) ans++;
			//moo << vis[i][j] << ' ';
		}
		//moo << endl;
	}
}

int aux2(int x, int y, int dx, int dy){
	int z = S[x][y] - '0';
	x += dx, y += dy;
	int res = 0;
	for(; x >= 0 && y >= 0 && x < N && y < M; x += dx, y += dy){
		res++;
		if(S[x][y] - '0' >= z) break;
		
	}
	return res;
}

int ans2 = 0;
void part2(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			int r = aux2(i, j, 1, 0) * aux2(i, j, -1, 0);
			r *= aux2(i, j, 0, 1) * aux2(i, j, 0, -1);
			ans2 = max(ans2, r);
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	string Cur;
	while(getline(eat, Cur)){
		if(Cur.size() == 0) break;
		S.push_back(Cur);
	}
	N = S.size();
	M = S[0].size();
	part1();
	part2();
	moo << ans << endl;
	moo << ans2 << endl;
	// solve();
	//moo << sum << endl;
}