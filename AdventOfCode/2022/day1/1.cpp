#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

vector<int> f;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	string l;
	int cur = 0;
	while(getline(cin, l)){
		if(l.size() == 0){
			f.push_back(cur);
			cur = 0;
		}else{
			cur += stoi(l);
		}
	}
	f.push_back(cur);
	sort(f.begin(), f.end(), greater<int>());
	moo << f[0] << endl;
}