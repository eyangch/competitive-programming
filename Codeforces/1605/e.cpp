#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[200000], B[200000], Q, X[200000], I[200000], sum[200000], calc[200000], res[200000];
multiset<int> sw;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	for(int i = 0; i < N; i++){
		eat >> B[i];
	}
	eat >> Q;
	for(int i = 0; i < Q; i++){
		eat >> X[i];
	}
	iota(I, I+Q, 0);
	sort(I, I+Q, [](int a, int b){
		return X[a] < X[b];
	});
	B[0] = 0;
	for(int i = 0; i < N; i++){
		A[i] -= B[i];
	}
	sum[0] = 1;
	for(int i = 1; i <= N; i++){
		for(int j = 2*i; j <= N; j += i){
			sum[j-1] -= sum[i-1];
		}
	}
	copy(A, A+N, calc);
	for(int i = 1; i <= N; i++){
		for(int j = 2*i; j <= N; j += i){
			calc[j-1] -= calc[i-1];
		}
	}
	int ans = 0;
	int mp = 0;
	for(int i = 0; i < N; i++){
		if(sum[i] == -1) calc[i] = -calc[i];
		//moo << calc[i] << ' ';
		if(sum[i] != 0 && calc[i] < 0) mp++;
		if(sum[i] != 0 && calc[i] >= 0) sw.insert(calc[i]), mp--;
		ans += abs(calc[i]);
	}
	//moo << endl;
	//moo << ans << endl;
	/*for(int i = 0; i < N; i++){
		moo << sum[i] << ' ';
	}
	moo << endl;*/
	for(int i = 0; i < Q; i++){
		int j = I[i];
		int x = X[j];
		int p = 0;
		if(i > 0) p = X[I[i-1]];
		while(sw.size() && *sw.begin() <= x){
			mp += 2;
			int diff = *sw.begin() - p;
			ans -= 2 * diff;
			sw.erase(sw.begin());
		}
		ans += mp * (x - p);
		res[j] = ans;
	}
	for(int i = 0; i < Q; i++){
		moo << res[i] << endl;
	}
}