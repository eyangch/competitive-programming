#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string S;

bool is_palindrome(int l, int r){
	if(r < l) return true;
	if(S[l] != S[r]) return false;
	return is_palindrome(l+1, r-1);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> S;
	int ans = 0;
	for(int i = 0; i < S.length(); i++){
		for(int j = i; j < S.length(); j++){
			if(!is_palindrome(i, j)){
				ans = max(ans, j-i+1);
			}
		}
	}
	moo << ans << endl;
}