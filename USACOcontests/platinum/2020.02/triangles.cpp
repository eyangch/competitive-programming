#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, ans = 0, D[600][300];
string S[300];

void flip(){
	for(int i = 0; i < N; i++){
		reverse(S[i].begin(), S[i].end());
	}
}

void rotate(){
	flip();
	for(int i = 0; i < N; i++){
		for(int j = 0; j < i; j++){
			swap(S[i][j], S[j][i]);
		}
	}
}

void solve(){
	for(int i = 0; i < 2*N; i++){
		for(int j = 0; j < N; j++) D[i][j] = 0;
	}
	for(int i = N-1; i >= 0; i--){
		for(int j = 0; j < N; j++){
			D[i+j][j] = (S[i][j] == '*');
			if(i < N-1 && j > 0) D[i+j][j] += D[i+j][j-1];
		}
	}
	for(int i = 0; i < 2*N; i++){
		for(int j = 1; j < N; j++){
			D[i][j] = max(D[i][j], D[i][j-1]);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(S[i][j] != '*') continue;
			int x = i, y = j;
			for(int k = 2; 1; k+=2){
				x--, y++;
				if(x < 0 || y >= N || i+j-k < 0) break;
				if(S[x][y] != '*') continue;
				int cur = D[i+j-k][j];
				int endy = j - k/2;
				if(endy > 0) cur -= D[i+j-k][endy-1];
				ans += cur;
			}
		}
	}
}

void elim(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(S[i][j] != '*') continue;
			for(int k = j+2; k < N; k += 2){
				if(S[i][k] != '*') continue;
				int med = (j+k)/2;
				int d = (k-j)/2;
				int x1 = i-d, x2 = i+d;
				if(x1 >= 0 && S[x1][med] == '*') ans--;
				if(x2 < N && S[x2][med] == '*') ans--;
			}
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("triangles.in", "r", stdin); freopen("triangles.out", "w", stdout);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> S[i];
	}
	for(int j = 0; j < 4; j++){
		solve();
		rotate();
	}
	elim();
	rotate();
	elim();
	moo << ans << endl;
}