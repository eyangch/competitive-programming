#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M, a[50000], K, b[50000];
int asp[50000], arm[50000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		int sum = 0;
		for(int i = 0; i < N; i++){
			eat >> a[i];
			sum += a[i];
		}
		eat >> K;
		for(int i = 0; i < K; i++){
			eat >> b[i];
			sum -= b[i];
		}
		if(sum != 0){
			moo << "No" << endl;
			continue;
		}
		for(int i = 0; i < N; i++){
			int c = a[i];
			while(true){
				if(c % M == 0){
					c /= M;
				}else{
					break;
				}
			}
			asp[i] = c;
			arm[i] = a[i]/c;
		}
		int ap = 0;
		bool bad = false;
		for(int i = 0; i < K; i++){
			int cs = 0;
			int rep = asp[ap];
			int mvs = b[i] / rep;
			//moo << "made it to " << i << ' ' << mvs << ' ' << b[i] << ' ' << ap << ' ' << a[ap] << ' ' << asp[ap] << ' ' << arm[ap] << endl;
			while(mvs > 1){
				if(mvs % M != 0){
					bad = true;
					break;
				}
				mvs /= M;
			}
			if(b[i] % rep != 0 || bad || mvs == 0){
				moo << "No" << endl;
				bad = true;
				break;
			}
			while(cs < b[i]){
				if(asp[ap] != rep){
					break;
				}
				if(b[i] - cs < asp[ap] * arm[ap]){
					arm[ap] -= (b[i] - cs) / asp[ap];
					cs = b[i];
				}else{
					cs += arm[ap] * asp[ap];
					ap++;
				}
			}
			if(cs != b[i]){
				moo << "No" << endl;
				bad = true;
				break;
			}
		}
		if(bad) continue;
		moo << "Yes" << endl;
	}
}