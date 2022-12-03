#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string S1, S2, S3;
int sum = 0;
int l[52], f[52];

void aux(string S){
	int N = S.length();
	fill(f, f+52, 0);
	for(int i = 0; i < N; i++){
		int sub = 'A' - 26;
		if(S[i] >= 'a'){
			sub = 'a';
		}
		if(f[S[i]-sub]) continue;
		f[S[i]-sub] = 1;
		l[S[i]-sub]++;
	}
}

void solve(){
	fill(l, l+52, 0);
	aux(S1);
	aux(S2);
	aux(S3);
	for(int i = 0; i < 52; i++){
		if(l[i] == 3) sum += i+1;
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	while(getline(cin, S1)){
		getline(cin, S2);
		getline(cin, S3);
		solve();
	}
	// solve();
	moo << sum << endl;
}