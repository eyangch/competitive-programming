#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> S;
		int sum = 0;
		int lst = 9;
		int dec = 1;
		while(S > 0){
			if(lst <= S){
				sum += lst * dec;
				S -= lst;
				dec *= 10;
				lst--;
			}else{
				sum += S * dec;
				S = 0;
			}
		}
		moo << sum << endl;
	}
}