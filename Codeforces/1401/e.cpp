#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct BIT{
	int a[1000002];
	void upd(int i, int x){
		for(i++; i <= 1000001; i += i & -i){
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

int N, M;
vector<int> ad[1000001], de[1000001];
vector<pair<int, int>> ve[1000001];
BIT bit;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	int fl = 0;
	for(int i = 0; i < N; i++){
		int y, lx, rx; eat >> y >> lx >> rx;
		ad[lx].push_back(y);
		de[rx].push_back(y);
		if(lx == 0 && rx == 1000000) fl++;
	}
	for(int i = 0; i < M; i++){
		int x, ly, ry; eat >> x >> ly >> ry;
		ve[x].push_back({ly, ry});
		if(ly == 0 && ry == 1000000) fl++;
	}
	int ans = fl+1;
	for(int i = 0; i <= 1000000; i++){
		for(int j : ad[i]){
			bit.upd(j, 1);
		}
		for(pair<int, int> j : ve[i]){
			int cur = bit.qry(j.second);
			if(j.first > 0) cur -= bit.qry(j.first - 1);
			ans += cur;
		}
		for(int j : de[i]){
			bit.upd(j, -1);
		}
	}
	moo << ans << endl;
}