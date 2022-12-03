#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[1000], D[1000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 1; i < N; i++){
		string s; eat >> s;
		if(s == "Patrik"){
			eat >> A[i];
		}else{
			int y; eat >> y >> A[i];
			A[i] += A[y-1];
		}
		D[i-1] = A[i] - A[i-1];
	}
	int mnv = 1e15, mni = 0;
	for(int i = 0; i < N-1; i++){
		if(D[i] < mnv){
			mnv = D[i];
			mni = i;
		}
	}
	moo << mnv << ' ' << mni+1 << ' ' << mni+2 << endl;
}