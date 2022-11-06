#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, R, S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> R >> S;;
	for(int i = 0; i < N; i++){
		int s = -1, e = 0;
		//moo << R << endl;
		for(int j = 0; j < R; j++){
			string a; eat >> a;
			//moo << "THING: " << a << endl;
			bool has = 0;
			for(char k : a){
				if(k == '#'){
					has = 1;
					break;
				}
			}
			if(has){
				e = j;
				if(!~s) s = j;
			}
		}
		//moo << s << ' ' << e << endl;
		moo << e - s << endl;
	}
}