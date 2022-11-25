#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct segment_tree{
	int cnt[800005], A[800005];
	void upd(int x, bool a, int y, int l=0, int r=199999, int v=1){
		if(l > x || r < x){
			return;
		}
		if(l == r){
			if(a){
				cnt[v] = 1;
				A[v] = y;
			}else{
				cnt[v] = 0;
				A[v] = 0;
			}
		}else{
			upd(x, a, y, l, (l+r)/2, v*2);
			upd(x, a, y, (l+r)/2+1, r, v*2+1);
			cnt[v] = cnt[v*2] + cnt[v*2+1];
			A[v] = A[v*2] + A[v*2+1];
		}
	}
	int walk(int sn, int cn=0, int l=0, int r=199999, int v=1){
		if(sn == 0) return 0;
		if(l == r){
			if(cn + cnt[v] == sn){
				return A[v];
			}else{
				return 1e16;
			}
		}else{
			if(cnt[v*2] + cn >= sn){
				return walk(sn, cn, l, (l+r)/2, v*2);
			}else{
				return walk(sn, cn+cnt[v*2], (l+r)/2+1, r, v*2+1) + A[v*2];
			}
		}
	}
};

int N, M, K, C[200000], I[200000], rI[200000];
int AN, AX[200000], BN, BX[200000];
int val[200000];
vector<int> vX, vY, vZ;
int X, Y, Z;

segment_tree S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M >> K;
	for(int i = 0; i < N; i++){
		eat >> C[i];
	}
	eat >> AN;
	for(int i = 0; i < AN; i++){
		eat >> AX[i];
		AX[i]--;
		val[AX[i]]++;
	}
	eat >> BN;
	for(int i = 0; i < BN; i++){
		eat >> BX[i];
		BX[i]--;
		val[BX[i]] += 2;
	}
	for(int i = 0; i < N; i++){
		if(val[i] == 1){
			vX.push_back(i);
		}
		if(val[i] == 2){
			vY.push_back(i);
		}
		if(val[i] == 3){
			vZ.push_back(i);
		}
	}
	iota(I, I+N, 0);
	sort(I, I+N, [](int a, int b){
		return C[a] < C[b];
	});
	for(int i = 0; i < N; i++){
		rI[I[i]] = i;
	}
	X = vX.size(), Y = vY.size(), Z = vZ.size();
	sort(vX.begin(), vX.end(), [](int a, int b){
		return C[a] < C[b];
	});
	sort(vY.begin(), vY.end(), [](int a, int b){
		return C[a] < C[b];
	});
	sort(vZ.begin(), vZ.end(), [](int a, int b){
		return C[a] < C[b];
	});
	for(int i = 0; i < N; i++){
		S.upd(rI[i], 1, C[i]);
	}
	int Xc = 0, Yc = 0, Zc = 0;
	for(int i = 0; i < min(Z, K); i++){
		Zc += C[vZ[i]];
		S.upd(rI[vZ[i]], 0, 0);
	}
	int ans = 1e16;
	for(int i = 0; i <= K; i++){
		if(K - i <= Z && i <= X && i <= Y){
			int req = M-i-K;
			int unused = S.walk(req);
			int tot = unused + Xc + Yc + Zc;
			ans = min(ans, tot);
			if(i < K){
				int add_bk = K-i-1;
				int cur = vZ[add_bk];
				S.upd(rI[cur], 1, C[cur]);
				Zc -= C[cur];
			}
		}
		if(i < X){
			S.upd(rI[vX[i]], 0, 0);
			Xc += C[vX[i]];
		}
		if(i < Y){
			S.upd(rI[vY[i]], 0, 0);
			Yc += C[vY[i]];
		}
	}
	moo << (ans >= 9e15 ? -1 : ans) << endl;
}