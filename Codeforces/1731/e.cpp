#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, D[1000000], nm[1000001], rnm[1000001];
vector<int> F[1000001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		int cost = 0;
		for(int i = N; i > 0; i--){
			nm[i] = N / i;
			rnm[i] = nm[i] * (nm[i]-1) / 2;
			for(int j = 2*i; j <= N; j += i){
				rnm[i] -= rnm[j];
			}
			//rnm[i] = N/i * nm[i];
			//moo << nm[i] << ' ';
		}
		/*moo << endl;
		for(int i = 0; i < N; i++){
			moo << rnm[i] << ' ';
		}*/
		//moo << endl;
		int i = N-1;
		while(i > 0){
			int ned = i;
			if(rnm[i+1] < ned){
				i--;
				continue;
			}
			if(ned > M){
				i--;
				continue;
			}
			//moo << "OK: " << i << endl;
			int mn = rnm[i+1] / ned;
			mn = min(mn, M / ned);
			rnm[i+1] -= ned * mn;
			M -= ned * mn;
			cost += mn * (i+1);
		}
		if(M) moo << -1 << endl;
		else moo << cost << endl;
	}
}