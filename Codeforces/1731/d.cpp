#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;
vector<int> A[10000], B[10000];

struct sparse_table{
	int N;
	vector<int> st[11], lg2;
	void init(int N, int (&arr)[1100]){
		for(int i = 0; i < 11; i++){
			st[i].resize(N);
		}
		lg2.resize(N+1);
		for(int i = 0; i < N; i++){
			st[0][i] = arr[i];
		}
		this->N = N;
		lg2[1] = 0;
		for(int i = 2; i <= N; i++){
			lg2[i] = lg2[i/2] + 1;
		}
		for(int i = 1; i < 11; i++){
			for(int j = 0; j + (1<<i) <= N; j++){
				st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
			}
		}
	}
	int qry(int l, int r){
		if(l == r) return st[0][l];
		int lg = lg2[r - l + 1];
		return min(st[lg][l], st[lg][r-(1<<(lg))+1]);
	}
};

int S[10000];

bool works(int X){
	for(int i = 0; i < N; i++){
        fill(B[i].begin(), B[i].end(), 0);
        S[i] = 0;
    }
	for(int i = 0; i + X - 1 < M; i++){
		//moo << "START " << i << endl;
		int L = i;
		int R = i+X-1;
		if(i == 0){
			for(int j = L; j <= R; j++){
				for(int k = 0; k < N; k++){
                    if(A[k][j] < X) S[k]++;
				}
			}
		}else{
			for(int k = 0; k < N; k++){
                if(A[k][R] < X) S[k]++;
				//S[k].insert(A[k][R]);
			}
		}
        int csum = 0;
		for(int j = 0; j + X - 1 < N; j++){
			int u = j;
			int l = j + X - 1;
            if(j == 0){
    			for(int k = u; k <= l; k++){
    				csum += S[k];
    			}
            }else{
                csum += S[l];
            }
            /*if(X == 5){
                moo << i << ' ' << j << ' ' << csum << endl;
            }*/
            if(csum == 0) return 1;
            csum -= S[u];
		}
		for(int k = 0; k < N; k++){
            if(A[k][L] < X) S[k]--;
			//S[k].erase(S[k].find(A[k][L]));
		}
	}
	
	return 0;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i < N; i++){
			A[i].resize(M);
            B[i].resize(M);
            fill(B[i].begin(), B[i].end(), 0);
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				eat >> A[i][j];
			}
		}
		int lo = 1, hi = N, mid = 0, ans = 0;
		while(lo <= hi){
			mid = (lo+hi)/2;
			//moo << "OK " << mid << endl; moo.flush();
			if(works(mid)){
				ans = mid;
				lo = mid+1;
			}else{
				hi = mid-1;
			}
			for(int i = 0; i < N; i++){
				S[i] = 0;
			}
		}
        //moo << works(5) << endl;
		moo << ans << endl;
	}
}