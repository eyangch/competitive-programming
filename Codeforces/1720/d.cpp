#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout

using namespace std;

struct trie{
	int bit;
	int res[4];
	trie *c[2];
	trie(int bit){
		c[0] = c[1] = NULL;
		this->bit = bit;
		res[0] = res[1] = res[2] = res[3] = 0;
	}
	void upd(int ai, int i, int x){
		int b1 = (ai >> bit) & 1;
		int b2 = (i >> bit) & 1;
		int cn = b1 * 2 + b2;
		res[cn] = max(res[cn], x);
		if(bit == 0) return;
		int z = b1 ^ b2;
		if(!c[z]){
			c[z] = new trie(bit-1);
		}
		c[z]->upd(ai, i, x);
	}
	int qry(int ai, int i){
		int b2 = (ai >> bit) & 1;
		int b1 = (i >> bit) & 1;
		int cn = b1 * 2 + b2;
		int ret = res[cn^1];
		if(bit == 0) return ret;
		int z = b1 ^ b2;
		if(c[z]){
			//moo << "TAKE: " << b1 << ' ' << b2 << ' ' << z << ' ' << cn << ' ' << res[cn] << endl;
			ret = max(ret, c[z]->qry(ai, i));
		}
		return ret;
	}
};

int T, N, A[300000];
trie *tr;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N;
		tr = new trie(30);
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		int ans = 0;
		for(int i = 0; i < N; i++){
			int x = tr->qry(A[i], i) + 1;
			ans = max(ans, x);
			//moo << x << endl;
			tr->upd(A[i], i, x);
		}
		moo << ans << endl;
	}
}