#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, Q, pf[26][1000001], ls[26], rs[26];
string S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		eat >> S >> Q;
		moo << "Case #" << tc << ": ";
		for(int i = 0; i < 26; i++){
			for(int j = 0; j < S.size(); j++){
				pf[i][j] = 0;
			}
		}
		for(int i = 0; i < S.size(); i++){
			if(i > 0){
				for(int j = 0; j < 26; j++){
					pf[j][i] = pf[j][i-1];
				}
			}
			pf[S[i]-'a'][i]++;
		}
		int ans = 0;
		while(Q--){
			int L, R; eat >> L >> R;
			L--, R--;
			int len = R-L+1;
			if(len % 2 == 0){
				continue;
			}
			fill(ls, ls+26, 0);
			fill(rs, rs+26, 0);
			int obo = 0;
			int obo2 = 0;
			for(int i = 0; i < 26; i++){
				ls[i] = pf[i][L+len/2];
				if(L > 0) ls[i] -= pf[i][L-1];
				rs[i] = pf[i][R];
				rs[i] -= pf[i][L+len/2];
				int ls2 = 0;
				if(L + len/2 > 0) ls2 = pf[i][L+len/2-1];
				if(L > 0) ls2 -= pf[i][L-1];
				int rs2 = pf[i][R];
				if(L + len/2 > 0) rs2 -= pf[i][L+len/2-1];
				if(ls[i] - rs[i] == 1){
					obo++;
				}else if(rs[i] == ls[i]){
					// lol
				}else{
					obo = 10;
				}
				if(rs2 - ls2 == 1){
					obo2++;
				}else if(rs2 == ls2){
					// lol
				}else{
					obo2 = 10;
				}
			}
			assert(obo != 0);
			assert(obo2 != 0);
			//moo << Q << ' ' << obo << ' ' << obo2 << ' ' << "OBOBOBOBO" << endl;
			if(obo == 1 || obo2 == 1){
				ans++;
			}
		}
		moo << ans << endl;
	}
}