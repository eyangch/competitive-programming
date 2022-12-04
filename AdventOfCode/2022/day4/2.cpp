#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string S1, S2, S3, S4;
int sum = 0;

int stuf(int A, int B, int C, int D){
	int f[1000];
	fill(f, f+1000, 0);
	for(int i = A; i <= B; i++){
		f[i] = 1;
	}
	if(f[C] == 1 || f[D] == 1){
		return 1;
	}
	return 0;
}

void solve(){
	int A = stoi(S1), B = stoi(S2);
	int C = stoi(S3), D = stoi(S4);
	sum += max(stuf(A, B, C, D), stuf(C, D, A, B));
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	while(getline(cin, S1, '-')){
		getline(cin, S2, ',');
		getline(cin, S3, '-');
		getline(cin, S4);
		solve();
	}
	// solve();
	moo << sum << endl;
}