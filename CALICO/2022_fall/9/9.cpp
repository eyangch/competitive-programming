#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, H, W, D;
string S[3050], OS[3050];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> H >> W >> D;
		eat.ignore(numeric_limits<std::streamsize>::max(), '\n');
		for(int i = 0; i < H+D+1; i++){
			S[i].clear();
		}
		for(int i = 0; i < H; i++){
			getline(eat, S[i]);
		}
		for(int i = 0; i < H+D+1; i++){
			S[i].resize(W+D+1, ' ');
			OS[i] = S[i];
		}
		for(int i = H-1; i >= 0; i--){
			for(int j = W-1; j >= 0; j--){
				if(S[i][j] == '+'){
					for(int k = 1; k <= D; k++){
						if(S[i+k][j+k] == '\\') break;
						S[i+k][j+k] = '\\';
					}
				}
			}
		}
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(OS[i][j] != ' ') S[i+D+1][j+D+1] = OS[i][j];
			}
		}
		for(int i = 0; i < H+D+1; i++){
			moo << S[i] << endl;
		}
	}
}