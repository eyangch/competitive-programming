#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, R, C;
string S[1000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ": ";
		eat >> R >> C;
		for(int i = 0; i < R; i++){
			eat >> S[i];
		}
		int trees = 0;
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(S[i][j] == '^') trees++;
			}
		}
		if(!trees){
			moo << "Possible" << endl;
			for(int i = 0; i < R; i++){
				for(int j = 0; j < C; j++){
					moo << '.';
				}
				moo << endl;
			}
			continue;
		}
		if(min(R, C) == 1){
			moo << "Impossible" << endl;
		}else{
			moo << "Possible" << endl;
			for(int i = 0; i < R; i++){
				for(int j = 0; j < C; j++){
					moo << '^';
				}
				moo << endl;
			}
		}
	}
}