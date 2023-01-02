#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K, A[500][500], mnx[250000], mny[250000], mxx[250000], mxy[250000];
int P[501][501];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	for(int i = 0; i < N*N; i++){
		mnx[i] = mny[i] = 1e15;
		mxx[i] = mxy[i] = -1e15;
	}
	set<int> occ;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			eat >> A[i][j];
			A[i][j]--;
			occ.insert(A[i][j]);
			mnx[A[i][j]] = min(mnx[A[i][j]], i);
			mny[A[i][j]] = min(mny[A[i][j]], j);
			mxx[A[i][j]] = max(mxx[A[i][j]], i);
			mxy[A[i][j]] = max(mxy[A[i][j]], j);
		}
	}
	int M = occ.size();
	if(K >= M){
		moo << K - M << endl;
		return 0;
	}
	/*for(int i = 0; i < N*N; i++){
		moo << mnx[i] << ' ' << mny[i] << ' ' << mxx[i] << ' ' << mxy[i] << endl;
	}*/
	bool f1 = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				P[j][k] = 0;
			}
		}
		for(int j = 0; j < N*N; j++){
			if(mnx[j] > 23523) continue;
			int s = max(mxx[j] - mnx[j], mxy[j] - mny[j]);
			//moo << s << endl;
			if(s > i) continue;
			int cmnx = max(0LL, mxx[j] - i);
			int cmny = max(0LL, mxy[j] - i);
			int cmxx = mnx[j], cmxy = mny[j];
			P[cmnx][cmny]++;
			P[cmnx][cmxy+1]--;
			P[cmxx+1][cmny]--;
			P[cmxx+1][cmxy+1]++;
		}
		for(int j = 0; j+i < N; j++){
			for(int k = 0; k+i < N; k++){
				if(j) P[j][k] += P[j-1][k];
				if(k) P[j][k] += P[j][k-1];
				if(j && k) P[j][k] -= P[j-1][k-1];
				if(P[j][k] == M - K || P[j][k] == M - K + 1){
					//moo << i << ' ' << j << ' ' << k << ' ' << P[j][k] << endl;
					f1 = 1;
					goto esc_f1;
				}
				//moo << P[j][k] << ' ';
			}
			//moo << endl;
		}
		//moo << endl;
	}
	esc_f1:;
	if(f1){
		moo << 1 << endl;
	}else{
		moo << 2 << endl;
	}
}