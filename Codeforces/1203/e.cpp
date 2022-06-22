#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, a[150000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> a[i];
	}
	sort(a, a+N);
	int mx = 0, ans = 0;
	for(int i = 0; i < N; i++){
		if(a[i] - 1 > mx){
			ans++;
			mx = a[i]-1;
		}else if(a[i] > mx){
			ans++;
			mx = a[i];
		}else if(a[i] + 1 > mx){
			ans++;
			mx = a[i]+1;
		}
	}
	moo << ans << endl;
}