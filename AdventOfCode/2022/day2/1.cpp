#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string S;
int sum = 0;

void solve(){
	char a = S[0], b = S[2];
	int s1 = S[2] - ('X') + 1;
	int s2 = 0;
	b -= ('X' - 'A');
	if(a == b){
		s2 = 3;
	}
	int x = a - 'A', y = b - 'A';
	if((x+1) % 3 == y){
		s2 = 6;
	}
	sum += s1 + s2;
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