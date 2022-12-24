#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100000], B[100000];
vector<int> F, I;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		F.clear();
		I.clear();
		for(int i = 0; i < N; i++){
			eat >> B[i];
			if(A[i] == 0){
				F.push_back(B[i]);
			}else{
				I.push_back(B[i]);
			}
		}
		sort(F.begin(), F.end(), greater<int>());
		sort(I.begin(), I.end(), greater<int>());
		int ans = 0;
		for(int i : F) ans += i;
		for(int i : I) ans += i;
		int mn = min(F.size(), I.size());
		if(F.size() == I.size()){
			ans += -min(F[mn-1], I[mn-1]);
		}
		for(int i = 0; i < mn; i++){
			ans += F[i] + I[i];
		}
		moo << ans << endl;
	}
}