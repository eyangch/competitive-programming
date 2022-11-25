#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, C, D, cN, dN, cI[100000], dI[100000];
vector<int> cc, cd, bc, bd;

int clown(int xN, int T, vector<int> &c, vector<int> &b, int (&I)[100000]){
	multiset<int> bt;
	int ptr = 0;
	int ret = -1e9;
	for(int i = xN-1; i >= 0; i--){
		int j = I[i];
		int r = T - c[j];
		while(ptr < xN && c[I[ptr]] <= r){
			bt.insert(b[I[ptr]]);
			ptr++;
		}
		int cb = b[j];
		bool f = 0;
		if(bt.count(cb)){
			bt.erase(bt.find(cb));
			f = 1;
		}
		if(bt.size()){
			int mx = *bt.rbegin();
			ret = max(ret, mx + cb);
		}
		if(f){
			bt.insert(cb);
		}
	}
	return ret;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> C >> D;
	for(int i = 0; i < N; i++){
		char t;
		int b, p;
		eat >> b >> p >> t;
		if(t == 'C'){
			bc.push_back(b);
			cc.push_back(p);
		}else{
			bd.push_back(b);
			cd.push_back(p);
		}
	}
	cN = cc.size();
	dN = cd.size();
	iota(cI, cI+cN, 0);
	iota(dI, dI+dN, 0);
	sort(cI, cI+cN, [](int a, int b){
		return cc[a] < cc[b];
	});
	sort(dI, dI+dN, [](int a, int b){
		return cd[a] < cd[b];
	});
	int mxC = -1e9, mxD = -1e9;
	for(int i = 0; i < cN; i++){
		int j = cI[i];
		if(cc[j] > C) break;
		mxC = max(mxC, bc[j]);
	}
	for(int i = 0; i < dN; i++){
		int j = dI[i];
		if(cd[j] > D) break;
		mxD = max(mxD, bd[j]);
	}
	int ans = mxC + mxD;
	int ansC = clown(cN, C, cc, bc, cI);
	int ansD = clown(dN, D, cd, bd, dI);
	moo << max({0LL, ans, ansC, ansD}) << endl;
}