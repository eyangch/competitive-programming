#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[3000], I[3000], D[3000], mx[3000][3000], mxi[3000][3000], ans[3000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	iota(I, I+N, 0);
	sort(I, I+N, [](int a, int b){
		return A[a] < A[b];
	});
	for(int i = 1; i < N; i++){
		D[i] = A[I[i]] - A[I[i-1]];
	}
	D[0] = A[I[0]];
	for(int i = 0; i < N; i++){
		mx[i][i] = D[i];
		mxi[i][i] = i;
		for(int j = i+1; j < N; j++){
			mx[i][j] = mx[i][j-1];
			mxi[i][j] = mxi[i][j-1];
			if(D[j] > mx[i][j-1]){
				mx[i][j] = D[j];
				mxi[i][j] = j;
			}
		}
	}
	int ans1 = 2 * N/3, ans2 = N/3, ans3 = 0;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			int d1 = N - j;
			int d2 = j - i;
			if(d1 * 2 < d2 || d2 * 2 < d1){
				continue;
			}
			int pd1 = D[ans1];
			int cd1 = D[j];
			int pd2 = D[ans2];
			int cd2 = D[i];
			int mxd = max(d1, d2);
			int mnd = min(d1, d2);
			int mn3 = i - (mxd/2 + (mxd % 2));
			int mx3 = i - mnd * 2;
			int pd3 = D[ans3];
			if(mn3 < 0){
				continue;
			}
			mx3 = max(0LL, mx3);
			int cd3 = mx[mx3][mn3];
			int k = mxi[mx3][mn3];
			if(cd1 > pd1){
				ans1 = j;
				ans2 = i;
				ans3 = k;
			}else if(cd1 == pd1){
				if(cd2 > pd2){
					ans1 = j;
					ans2 = i;
					ans3 = k;
				}else if(cd2 == pd2){
					if(cd3 > pd3){
						ans1 = j;
						ans2 = i;
						ans3 = k;
					}
				}
			}
		}
	}
	for(int i = 0; i < ans3; i++){
		ans[I[i]] = -1;
	}
	for(int i = ans3; i < ans2; i++){
		ans[I[i]] = 3;
	}
	for(int i = ans2; i < ans1; i++){
		ans[I[i]] = 2;
	}
	for(int i = ans1; i < N; i++){
		ans[I[i]] = 1;
	}
	for(int i = 0; i < N; i++){
		moo << ans[i] << ' ';
	}
	moo << endl;
}