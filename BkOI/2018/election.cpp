#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;
using namespace __gnu_pbds;

struct segtree{
	int A[2000005], S[2000005];
	void init(){
		fill(A, A+2000005, 0);
		fill(S, S+2000005, 0);
	}
	void upd(int i, int x, int l=0, int r=499999, int v=1){
		if(l > i || r < i) return;
		if(l == r){
			A[v] = min(x, 0LL);
			S[v] = x;
			return;
		}
		upd(i, x, l, (l+r)/2, v*2);
		upd(i, x, (l+r)/2+1, r, v*2+1);
		S[v] = S[v*2] + S[v*2+1];
		A[v] = min(A[v*2], S[v*2] + A[v*2+1]);
	}
	pair<int, int> qry(int i, int l=0, int r=499999, int v=1){
		if(r < i) return {0, 0};
		if(l >= i){
			return {A[v], S[v]};
		}
		pair<int, int> q1 = qry(i, l, (l+r)/2, v*2);
		pair<int, int> q2 = qry(i, (l+r)/2+1, r, v*2+1);
		int c1 = q1.second + q2.first;
		int c2 = q1.first;
		return {min(c1, c2), q1.second + q2.second};
	}
};

int N, Q, ans[500000];
string S;
pair<int, int> A[500000];
vector<int> W[500000];
segtree segt;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> S >> Q;
	for(int i = 0; i < Q; i++){
		eat >> A[i].first >> A[i].second;
		A[i].first--, A[i].second--;
		W[A[i].second].push_back(i);
	}
	segt.init();
	stack<int> st;
	for(int i = 0; i < N; i++){
		if(S[i] == 'T'){
			oset.insert(i);
			st.push(i);
		}
		if(S[i] == 'C'){
			if(!st.empty()){
				int x = st.top();
				st.pop();
				oset.erase(x);
				segt.upd(x, -1);
			}
			segt.upd(i, 1);
		}
		for(int j : W[i]){
			int q = segt.qry(A[j].first).first;
			ans[j] = -q + (st.size() - oset.order_of_key(A[j].first));
		}
	}
	for(int i = 0; i < Q; i++){
		moo << ans[i] << endl;
	}
}