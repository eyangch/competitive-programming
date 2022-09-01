#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;
string C;
bool A[200], ans[200];

void print(int sz){
	for(int i = 0; i < sz; i++){
		if(ans[i]) moo << '-';
		else moo << '.';
	}
	moo << endl;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	for(int tc = 1; tc <= T; tc++){
		moo << "Case #" << tc << ":" << endl;
		eat >> N >> C;
		fill(A, A+200, 1);
		for(int i = 0; i < (int)C.size(); i++){
			A[i] = (C[i] == '-');
		}
		for(int i = 0; i < N-1; i++){
			for(int j = 0; j < 200; j++){
				ans[j] = !A[j];
			}
			for(int j = 0; j < 32; j++){
				if((i>>j)&1){
					ans[199-j] = 1;
				}
			}
			print(200);
		}
	}
}