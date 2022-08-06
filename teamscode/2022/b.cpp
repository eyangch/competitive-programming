#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, A, B, M;

int calc(int X){
	X++;
	int div = 1;
	int cur = 1;
	while(cur < M){
		cur = (cur+1) * 2 - 1, div *= 2;
	}
	return X/div;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> A >> B >> M;
		int a = calc(B);
		int b = calc(A-1);
		moo << a-b << endl;
	}
}