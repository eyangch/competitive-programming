#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string S;
int sum = 0;
bool l[52];

void solve(){
	int N = S.length();
	fill(l, l+52, 0);
	for(int i = 0; i < N/2; i++){
		int sub = 'A' - 26;
		if(S[i] >= 'a'){
			sub = 'a';
		}
		l[S[i]-sub] = 1;
	}
	for(int i = N/2; i < N; i++){
		int sub = 'A' - 26;
		if(S[i] >= 'a'){
			sub = 'a';
		}
		if(l[S[i]-sub]){
			sum += S[i]-sub+1;
			//moo << S[i] - sub + 1 << endl;
			break;
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	while(getline(cin, S)){
		solve();
	}
	// solve();
	moo << sum << endl;
}