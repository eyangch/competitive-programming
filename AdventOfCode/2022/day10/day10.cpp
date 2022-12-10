#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M;
string S;

int cyc;
int cur = 1;
int ans1[500];
void part1(){
	if(S[0] == 'n'){
		ans1[++cyc] = cur;
	}else{
		int x = stoi(S.substr(5));
		if(cyc > 400) return;
		ans1[++cyc] = cur;
		ans1[++cyc] = cur;
		cur += x;
	}
}

int ans2;
void part2(int i, int j){
	int x = i * 40 + j + 1;
	if(abs(ans1[x] - j) <= 1){
		moo << '#';
	}else{
		moo << '.';
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	while(getline(eat, S)){
		if(S.size() == 0) break;
		part1();
	}
	int res1 = 0;
	for(int i = 20; i <= 220; i += 40){
		res1 += ans1[i] * i;
		//moo << ans1[i] << ' ' << i << ' ' << ans1[i] * i << endl;
	}
	moo << res1 << endl;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 40; j++){
			part2(i, j);
		}
		moo << endl;
	}
	//moo << cyc << endl;
	// solve();
	//moo << sum << endl;
}