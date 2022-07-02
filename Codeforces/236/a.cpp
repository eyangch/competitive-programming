#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int x[26];
string s;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> s;
	for(char i : s){
		x[i-'a'] = 1;
	}
	moo << ((accumulate(x, x+26, 0) & 1) ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
}