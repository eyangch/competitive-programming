#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string S;
int ans = 0;
map<string, int> sz;
vector<string> cur;

void solve(){
	if(S[0] == '$'){
		S = S.substr(2);
		if(S[0] == 'c'){
			S = S.substr(3);
			if(S == ".."){
				cur.pop_back();
			}else{
				cur.push_back(S);
			}
		}
	}else{
		if(S[0] != 'd'){
			int n = 0;
			for(int i = 0; i < S.length(); i++){
				if(!isdigit(S[i]))break;
				n = n * 10;
				n += (S[i] - '0');
				//n = min(n, 100001LL);
			}
			string cz;
			for(int i = 0; i < cur.size(); i++){
				cz += cur[i];
				sz[cz] += n;
			}
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	cur.push_back("/");
	while(getline(cin, S)){
		if(S.size() == 0) break;
		solve();
	}
	int rem = sz["/"] - 40000000;
	int mn = 1e15;
	for(pair<string, int> i : sz){
		if(i.second <= 100000){
			ans += i.second;
		}
		if(i.second < mn && i.second >= rem){
			mn = i.second;
		}
	}
	moo << ans << endl;
	moo << mn << endl;
	// solve();
	//moo << sum << endl;
}