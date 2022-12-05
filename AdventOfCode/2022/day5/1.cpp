#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string S1, S2, S3, S4;
int sum = 0;
vector<char> st[100];

void add(){
	if(isdigit(S1[1])) return;
	int idx = 1;
	for(int i = 1; i < S1.size(); i += 4){
		if(S1[i] != ' '){
			st[idx].push_back(S1[i]);
		}
		idx++;
	}
}

void solve(){
	int a = stoi(S2);
	int b = stoi(S3);
	int c = stoi(S4);
	for(int i = 0; i < a; i++){
		st[c].push_back(st[b].back());
		st[b].pop_back();
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	while(getline(cin, S1)){
		if(S1.length() == 0) break;
		add();
	}
	for(int i = 0; i  <100; i++){
		reverse(st[i].begin(), st[i].end());
	}
	while(getline(cin, S1, ' ')){
		getline(cin, S2, ' ');
		getline(cin, S1, ' ');
		getline(cin, S3, ' ');
		getline(cin, S1, ' ');
		getline(cin, S4);
		solve();
	}
	for(int i = 0; i < 100; i++){
		if(st[i].size() == 0) continue;
		moo << st[i].back();
	}
	moo << endl;
	// solve();
	//moo << sum << endl;
}