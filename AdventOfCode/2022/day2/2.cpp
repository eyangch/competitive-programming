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
	int s1 = (b - 'X') * 3;
	int y = b - 'Y';
	int x = a - 'A';
	x += y;
	x = (x + 3) % 3;
	sum += s1 + x + 1;
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