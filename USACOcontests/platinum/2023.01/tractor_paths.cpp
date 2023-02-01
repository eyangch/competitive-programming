#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct lift{
	int N;
	int n1[20][200000];
	int n2[20][200000];
	int p1[20][200000];
	int p2[20][200000];
	int pw[20];
	void init(int N, int (&L)[200000], int (&R)[200000], int (&pfx)[200000], int (&ppfx)[200000]){
		this->N = N;
		for(int i = 0; i < N; i++){
			n1[0][i] = L[i];
		}
		for(int i = 1; i < 20; i++){
			for(int j = 0; j < N; j++){
				n1[i][j] = n1[i-1][n1[i-1][j]];
			}
		}
		for(int i = 0; i < N; i++){
			n2[0][i] = R[i];
		}
		for(int i = 1; i < 20; i++){
			for(int j = 0; j < N; j++){
				n2[i][j] = n2[i-1][n2[i-1][j]];
			}
		}
		for(int i = 0; i < N; i++){
			p1[0][i] = ppfx[L[i]];
		}
		for(int i = 1; i < 20; i++){
			for(int j = 0; j < N; j++){
				p1[i][j] = p1[i-1][j] + p1[i-1][n1[i-1][j]];
			}
		}
		for(int i = 0; i < N; i++){
			p2[0][i] = pfx[R[i]];
		}
		for(int i = 1; i < 20; i++){
			for(int j = 0; j < N; j++){
				p2[i][j] = p2[i-1][j] + p2[i-1][n2[i-1][j]];
			}
		}
		pw[0] = 1;
		for(int i = 1; i < 20; i++){
			pw[i] = pw[i-1] * 2;
		}
	}
	pair<int, int> qry1(int a, int b){
		int ans1 = 0, ans2 = 0;
		for(int i = 19; i >= 0; i--){
			if(n1[i][b] <= a) continue;
			ans2 += p1[i][b];
			b = n1[i][b];
			ans1 += pw[i];
		}
		ans1++;
		//ans2 += p1[0][b];
		return {ans1, ans2};
	}
	pair<int, int> qry2(int a, int b){
		int ans1 = 0, ans2 = 0;
		for(int i = 19; i >= 0; i--){
			if(n2[i][a] >= b) continue;
			ans2 += p2[i][a];
			a = n2[i][a];
			ans1 += pw[i];
		}
		ans1++;
		//ans2 += p2[0][a];
		return {ans1, ans2};
	}
};

int N, Q;
string T_str, B_str;
bool B[200000];
pair<int, int> T[200000];
int Li[200000], Ri[200000];
int L[200000], R[200000];
int pfx[200000], ppfx[200000];

lift lif;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> Q >> T_str >> B_str;
	for(int i = 0; i < N; i++){
		B[i] = (B_str[i] == '1');
	}
	pfx[0] = B[0];
	for(int i = 1; i < N; i++){
		pfx[i] = pfx[i-1] + B[i];
	}
	ppfx[0] = 0;
	for(int i = 1; i < N; i++){
		ppfx[i] = pfx[i-1];
	}
	queue<int> Ls;
	int cnt = 0;
	for(int i = 0; i < 2*N; i++){
		if(T_str[i] == 'L'){
			Ls.push(i);
		}else{
			int x = Ls.front();
			Ls.pop();
			Li[cnt] = x;
			Ri[cnt] = i;
			T[cnt++] = {x, i};
		}
	}
	assert(Ls.empty());
	for(int i = 0; i < N; i++){
		auto it = upper_bound(Ri, Ri+N, Li[i]);
		L[i] = it - Ri;
		it = upper_bound(Li, Li+N, Ri[i]);
		R[i] = it - Li - 1;
		//moo << L[i] << ' ' << R[i] << endl;
		//moo.flush();
	}
	lif.init(N, L, R, pfx, ppfx);
	for(int i = 0; i < Q; i++){
		int a, b; eat >> a >> b;
		a--, b--;
		int ans1 = 0, ans2 = 0;
		/*int x = a, y = b;
		while(true){
			x = R[x];
			ans1++;
			if(x >= b) break;
			ans2 += pfx[x];
		}
		while(true){
			y = L[y];
			if(a >= y) break;
			ans2 -= ppfx[y];
		}
		if(B[a]) ans2++;
		if(B[b]) ans2++;*/

		pair<int, int> x1 = lif.qry1(a, b);
		pair<int, int> x2 = lif.qry2(a, b);
		assert(x1.first == x2.first);
		ans1 = x1.first;
		ans2 = x2.second - x1.second;
		if(B[a]) ans2++;
		if(B[b]) ans2++;
		moo << ans1 << ' ' << ans2 << endl;
	}
}