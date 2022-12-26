#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, R[300][300], A[300];

void dc(int l, int r, int m, bool mx){
	if(l >= r) return;
	int f = R[l][r];
	int x = -1;
	if(l == m){
		for(int i = r; i > l; i--){
			if(R[l][i-1] < f){
				x = i;
				break;
			}
		}
	}else{
		for(int i = l; i < r; i++){
			if(R[i+1][r] < f){
				x = i;
				break;
			}
		}
	}
	if(x == -1){
		for(int i = l; i <= r; i++){
			A[i] = A[m];
		}
		return;
	}
	if(mx){
		A[x] = A[m] - f;
	}else{
		A[x] = A[m] + f;
	}
	if(l == m){
		dc(l+1, x, x, !mx);
		dc(x, r, x, !mx);
	}else{
		dc(l, x, x, !mx);
		dc(x, r-1, x, !mx);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		for(int j = i; j < N; j++){
			eat >> R[i][j];
		}
	}
	int m = -1, f = R[0][N-1];
	for(int i = 0; i < N-1; i++){
		if(R[i+1][N-1] != f){
			m = i;
			break;
		}
	}
	if(~m){
		dc(0, m, m, 0);
		dc(m, N-1, m, 0);
	}
	for(int i = 0; i < N-1; i++){
		moo << A[i] << ' ';
	}
	moo << A[N-1] << endl;
}