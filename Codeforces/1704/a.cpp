#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;
string a, b;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M >> a >> b;
		bool good = 1;
		for(int i = 0; i < M-1; i++){
			if(a[N-i-1] != b[M-i-1]) good = false;
		}
		if(good){
			good = false;
			for(int i = 0; i <= N-M; i++){
				if(a[i] == b[0]) good = true;
			}
		}
		if(good) moo << "YES" << endl;
		else moo << "NO" << endl;
	}
}