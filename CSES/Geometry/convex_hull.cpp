#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int cross(pair<int, int> u, pair<int, int> v){
	return u.first * v.second - u.second * v.first;
}

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
	return cross({b.first-a.first, b.second-a.second}, {c.first-b.first, c.second-b.second});
}

int N;
pair<int, int> P[200000];

vector<pair<int, int>> convex_hull(){
	vector<pair<int, int>> ans;
	for(int i = 0; i < N; i++){
		while(ans.size() > 1){
			if(ccw(ans[ans.size()-2], ans[ans.size()-1], P[i]) >= 0) break;
			ans.pop_back();
		}
		ans.push_back(P[i]);
	}
	return ans;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> P[i].first >> P[i].second;
	}
	pair<int, int> piv = {1e18, 1e18};
	for(int i = 0; i < N; i++){
		if(P[i].first < piv.first){
			piv = P[i];
		}
	}
	sort(P, P+N, [&](pair<int, int> a, pair<int, int> b){
		if(a == piv) return true;
		if(b == piv) return false;
		int z = ccw(piv, a, b);
		return (z == 0 ? a > b : z > 0);
	});
	vector<pair<int, int>> ansCCW = convex_hull();
	sort(P, P+N, [&](pair<int, int> a, pair<int, int> b){
		if(a == piv) return true;
		if(b == piv) return false;
		int z = ccw(piv, a, b);
		return (z == 0 ? a < b : z > 0);
	});
	vector<pair<int, int>> ansCW = convex_hull();
	vector<pair<int, int>> ans;
	for(auto i : ansCCW) ans.push_back(i);
	for(auto i : ansCW) ans.push_back(i);
	sort(ans.begin(), ans.end());
	int sz = unique(ans.begin(), ans.end()) - ans.begin();
	moo << sz << endl;
	for(int i = 0; i < sz; i++){
		moo << ans[i].first << ' ' << ans[i].second << endl;
	}
}