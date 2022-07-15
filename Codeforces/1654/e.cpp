#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct semi_safe_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

int N, A[100000], tmp[100000];;
unordered_map<int, int, semi_safe_hash> dp1, dp2[100000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	int ans = 0;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	for(int i = -100; i <= 100; i++){
		dp1.clear();
		for(int j = 0; j < N; j++){
			int pv = 0;
			if(dp1.count(A[j]-i*j)){
				pv = dp1[A[j]-i*j];
			}
			dp1[A[j]-i*j] = pv + 1;
			ans = max(ans, pv+1);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = i-1; j >= 0 && i - j <= 100; j--){
			int d1 = i - j;
			int d2 = A[i] - A[j];
			if(d2 % d1 != 0) continue;
			dp2[i][d2/d1] = max(dp2[i][d2/d1], dp2[j][d2/d1]+1);
			dp2[i][d2/d1] = max(dp2[i][d2/d1], 2LL);
		}
		for(pair<int, int> j : dp2[i]){
			ans = max(ans, j.second);
		}
	}
	moo << N - ans << endl;
}