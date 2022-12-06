#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string S;

void solve(){
	for(int i = 13; i < S.length(); i++){
		set<int> s;
		for(int j = 0; j < 14; j++){
			s.insert(S[i-j]);
		}
		if(s.size() == 14){
			moo << i+1 << endl;
			return;
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	while(getline(cin, S)){
		if(S.size() == 0) break;
		solve();
	}
	// solve();
	//moo << sum << endl;
}