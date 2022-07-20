#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T;
string s;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> s;
		if(tolower(s[0]) == 'y' && tolower(s[1]) == 'e' && tolower(s[2]) == 's'){
			moo << s << endl;
		}else{
			moo << "no" << endl;
		}
	}
}