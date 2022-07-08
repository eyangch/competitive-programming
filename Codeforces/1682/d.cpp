#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;
string s;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> s;
		set<pair<int, int>> ans;
		int cnt1 = 0;
		for(char i : s){
			if(i == '1') cnt1++;
		}
		if(cnt1 % 2 == 1 || cnt1 == 0){
			moo << "NO" << endl;
			continue;
		}
		int enc1 = 1;
		int f1 = 0;
		for(int i = 1; i < N; i++){
			ans.insert({0, i});
		}
		int pv = -1;
		for(int i = 1; i < N; i++){
			if(s[i] == '1') enc1++;
			if(s[i] == '1' && f1) enc1++;
			if(s[i] == '1' && s[i-1] == '0' && i > 1) f1 = 1;
			if(s[i] == '0'){
				if(enc1 >= 2){
					ans.erase({0, i-1});
					ans.insert({i-1, i});
				}else if(f1 && (enc1 == 1 || s[i-1] == '0')){
					ans.erase({pv, i-1});
					ans.erase({0, i});
					ans.insert({i-1, i});
					ans.insert({pv, i});
				}else{
					ans.erase({0, i+1});
					ans.insert({i, i+1});
					pv = i;
				}
				if(enc1 < 2) enc1 = 0;
			}
		}
		moo << "YES" << endl;
		for(pair<int, int> i : ans){
			moo << i.first+1 << ' ' << i.second+1 << endl;
		}
	}
}