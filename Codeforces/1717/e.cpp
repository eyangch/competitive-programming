#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N;
vector<int> F[100001];
int occ[100001];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 1; i <= N; i++){
		reverse(F[i].begin(), F[i].end());
		for(int j = 2*i; j <= N; j+=i){
			F[j].push_back(i);
		}
	}
	int ans = 0;
	for(int c = 1; c <= N; c++){
		int s = N-c;
		for(int f : F[s]){
			occ[f] = s / f - 1;
		}
		for(int f : F[s]){
			for(int g : F[f]){
				occ[g] -= occ[f];
			}
		}
		for(int f : F[s]){
			ans = (ans + occ[f] * lcm(c, f) % MOD) % MOD;
		}
	}
	moo << ans << endl;
}