#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100000];
vector<int> P;
int sieve[5000005];
int dp[5000005];
int pm4[4];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	P.push_back(1);
	for(int i = 2; i <= 5000000; i++){
		if(sieve[i]) continue;
		P.push_back(i);
		for(int j = 2*i; j <= 5000000; j += i){
			sieve[j] = 1;
		}
	}
	dp[0] = 0;
	for(int i = 1; i <= 5000000; i++){
		if(!sieve[i]){
			pm4[i%4] = i;
		}
		if(i%4 == 0){
			dp[i] = dp[i-2]+1;
		}else{
			dp[i] = dp[i-pm4[i%4]]+1;
		}
	}
	/*for(int i = 400000; i < 400005; i++){
		moo << dp[i] << ' ';
	}moo << endl;*/
	//moo << P.size() << endl;
	eat >> T;
	while(T--){
		eat >> N;
		int mn = 1e15;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			A[i] = dp[A[i]];
			if(A[i]/2 < mn/2){
				mn = A[i];
			}
		}
		if(mn%2 == 0){
			moo << "Farmer Nhoj" << endl;
		}else{
			moo << "Farmer John" << endl;
		}
	}
}