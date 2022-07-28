#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

struct BIT{
	int N, a[2000001];
	void init(int N){
		this->N = N;
		fill(a, a+N, 0);
	}
	void upd(int i, int x){
		for(i++; i <= N; i += i & -i){
			a[i] += x;
		}
	}
	int qry(int i){
		int ret = 0;
		for(i++; i > 0; i -= i & -i){
			ret += a[i];
		}
		return ret;
	}
};

int T, N, M, A[1000000], B[1000000], F[2000000], L[1000000];
BIT bit;

void dc(int al, int ar, int bl, int br){
	if(bl > br) return;
	al = max(0LL, al);
	int m = (bl + br) / 2;
	int cur = 0;
	for(int i = al; i <= ar; i++){
		if(A[i] < B[m]) cur++;
	}
	int mn = cur, mni = al-1;
	for(int i = al; i <= ar; i++){
		if(A[i] < B[m]) cur--;
		if(A[i] > B[m]) cur++;
		if(cur < mn){
			mn = cur;
			mni = i;
		}
	}
	L[m] = mni;
	dc(al, mni, bl, m-1);
	dc(mni+1, ar, m+1, br);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		for(int i = 0; i < N; i++){
			eat >> A[i];
			F[i] = A[i];
		}
		for(int i = 0; i < M; i++){
			eat >> B[i];
			F[i+N] = B[i];
		}
		sort(F, F+N+M);
		int lst = unique(F, F+N+M) - F;
		bit.init(lst+1);
		for(int i = 0; i < N; i++){
			A[i] = lower_bound(F, F+lst, A[i]) - F;
		}
		for(int i = 0; i < M; i++){
			B[i] = lower_bound(F, F+lst, B[i]) - F;
		}
		sort(B, B+M);
		dc(0, N-1, 0, M-1);
		vector<int> x;
		int pv = N-1;
		for(int i = M-1; i >= 0; i--){
			for(; pv > L[i]; pv--){
				x.push_back(A[pv]);
			}
			x.push_back(B[i]);
		}
		for(; pv >= 0; pv--){
			x.push_back(A[pv]);
		}
		reverse(x.begin(), x.end());
		int ans = 0;
		for(int i = x.size()-1; i >= 0; i--){
			ans += bit.qry(x[i]-1);
			bit.upd(x[i], 1);
		}
		moo << ans << endl;
	}
}