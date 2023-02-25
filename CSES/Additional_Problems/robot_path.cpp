#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct ins{
	char d;
	int x;
};

struct seg{
	int x, y, y2, ty, time;
};

struct segset{
	set<pair<int, int>> S;
	void add(int a, int b){
		S.insert({a, b});
	}
	int isct(int a, int b){
		auto it = S.upper_bound({b, -1e18});
		if(it != S.begin()){
			it--;
			if(it->second >= a){
				return min(b, it->second);
			}
		}
		return 1e18;
	}
	void clear(){
		S.clear();
	}
};

int N, ans = 0;
vector<ins> I;
//vector<seg> st, en, hz;

void flip(){
	for(auto &i : I){
		if(i.d == 'U') i.d = 'R';
		else if(i.d == 'D') i.d = 'L';
		else if(i.d == 'L') i.d = 'D';
		else if(i.d == 'R') i.d = 'U';
	}
}

void prnt(int x){
	if(x < ans){
		moo << x << endl;
	}
}

void solvehz(){
	vector<seg> hz;
	int cx = 0, cy = 0, time = 0;
	for(auto i : I){
		if(i.d == 'L'){
			hz.push_back({cx, cy, (cy -= i.x), 0, time});
		}
		if(i.d == 'R'){
			hz.push_back({cx, cy, (cy += i.x), 1, time});
		}
		if(i.d == 'U'){
			cx += i.x;
		}
		if(i.d == 'D'){
			cx -= i.x;
		}
		time += i.x;
	}
	sort(hz.begin(), hz.end(), [](seg a, seg b){
		if(a.x == b.x){
			return a.time < b.time;
		}
		return a.x < b.x;
	});
	int curx = -1;
	segset S1, S2;
	for(int i = 0; i < (int)hz.size(); i++){
		if(hz[i].x != curx){
			S1.clear(), S2.clear();
		}
		curx = hz[i].x;
		if(hz[i].ty == 0){
			int X1 = S1.isct(hz[i].y2, hz[i].y);
			if(X1 != 1e18){
				int itime = hz[i].time + hz[i].y - X1;
				ans = min(ans, itime);
			}
			S1.add(hz[i].y2, hz[i].y);
			S2.add(-hz[i].y, -hz[i].y2);
		}else{
			int X2 = -S2.isct(-hz[i].y2, -hz[i].y);
			if(X2 != -1e18){
				int itime = hz[i].time + X2 - hz[i].y;
				ans = min(ans, itime);
			}
			S1.add(hz[i].y, hz[i].y2);
			S2.add(-hz[i].y2, -hz[i].y);
		}
	}
}

struct segment_tree{
	int A[800001];
	void clear(){
		fill(A, A+800001, 1e18);
	}
	void upd(int x, int y, int l=0, int r=200000, int v=1){
		if(l > x || r < x) return;
		if(l == r){
			A[v] = y;
		}else{
			upd(x, y, l, (l+r)/2, v*2);
			upd(x, y, (l+r)/2+1, r, v*2+1);
			A[v] = min(A[v*2], A[v*2+1]);
		}
	}
	int qry(int ql, int qr, int l=0, int r=200000, int v=1){
		if(l > qr || r < ql) return 1e18;
		if(l >= ql && r <= qr){
			return A[v];
		}
		int a = qry(ql, qr, l, (l+r)/2, v*2);
		int b = qry(ql, qr, (l+r)/2+1, r, v*2+1);
		return min(a, b);
	}
} T1, T2;

int ts(pair<int, int> y, vector<pair<int, int>> &yv){
	return (lower_bound(yv.begin(), yv.end(), y) - yv.begin());
}

void solveis(){
	T1.clear(), T2.clear();
	vector<seg> up1, up2, hz;
	vector<pair<int, int>> yv;
	int cx = 0, cy = 0, time = 0;
	for(auto i : I){
		yv.push_back({cy, time});
		if(i.d == 'L'){
			hz.push_back({cx, (cy -= i.x), cy + i.x, 0, time});
		}
		if(i.d == 'R'){
			hz.push_back({cx, cy, (cy += i.x), 1, time});
		}
		if(i.d == 'U'){
			if(i.x > 1){
				up1.push_back({cy, cx+1, (cx += i.x) - 1, 0, time});
				up2.push_back({cy, cx-1, 1, 0, time});
			}else{
				cx += i.x;
			}
		}
		if(i.d == 'D'){
			if(i.x > 1){
				up1.push_back({cy, (cx -= i.x)+1, cx + i.x-1, 1, time});
				up2.push_back({cy, cx + i.x-1, 1, 1, time});
			}else{
				cx -= i.x;
			}
		}
		yv.push_back({cy, time});
		time += i.x;
	}
	sort(yv.begin(), yv.end());
	for(auto &i : hz){
		i.y = ts({i.y-1, 1e18}, yv);
		i.y2 = ts({i.y2+1, 0}, yv)-1;
	}
	for(auto &i : up1){
		i.x = ts({i.x, i.time}, yv);
	}
	for(auto &i : up2){
		i.x = ts({i.x, i.time}, yv);
	}
	sort(up1.begin(), up1.end(), [](seg a, seg b){
		if(a.x == b.x){
			return a.time < b.time;
		}
		return a.y < b.y;
	});
	sort(up2.begin(), up2.end(), [](seg a, seg b){
		if(a.x == b.x){
			return a.time < b.time;
		}
		return a.y < b.y;
	});
	sort(hz.begin(), hz.end(), [](seg a, seg b){
		if(a.x == b.x){
			return a.time < b.time;
		}
		return a.x < b.x;
	});
	int hzp = 0, up1p = 0, up2p = 0;
	auto runHZ = [&](){
		seg c = hz[hzp];
		int mnup = T1.qry(c.y, c.y2) + c.x;
		int mndn = T2.qry(c.y, c.y2) - c.x;
		if(mnup < c.time) mnup = 1e18;
		if(mndn < c.time) mndn = 1e18;
		ans = min({ans, mnup, mndn});
		hzp++;
	};
	auto runUP1 = [&](){
		seg c = up1[up1p];
		if(c.ty == 0){
			T1.upd(c.x, c.time - (c.y-1));
		}else{
			T2.upd(c.x, c.time + (c.y2+1));
		}
		up1p++;
	};
	auto runUP2 = [&](){
		seg c = up2[up2p];
		if(c.ty == 0){
			T1.upd(c.x, 1e18);
		}else{
			T2.upd(c.x, 1e18);
		}
		up2p++;
	};
	while(hzp < hz.size()){
		int u1 = 1e18, u2 = 1e18;
		if(up1p < up1.size()){
			u1 = up1[up1p].y;
		}
		int h = hz[hzp].x;
		if(up2p < up2.size()){
			u2 = up2[up2p].y;
		}
		if(u1 <= h && u1 <= u2){
			runUP1();
		}else if(h <= u2){
			runHZ();
		}else{
			runUP2();
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	char cd = '*';
	int amt = 0;
	for(int i = 0; i < N; i++){
		char d;
		int x; eat >> d >> x;
		ans += x;
		if(d == cd){
			amt += x;
			continue;
		}
		if(cd != '*') I.push_back({cd, amt});
		cd = d, amt = x;
	}
	I.push_back({cd, amt});
	solvehz();
	solveis();
	flip();
	solvehz();
	solveis();
	moo << ans << endl;
}