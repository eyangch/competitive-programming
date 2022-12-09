#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M;
string S;

set<pair<int, int>> sl;
int xh = 0, yh = 0, px, py, xt = 0, yt = 0;
int ans = 0;
void part1(){
	char d = S[0];
	int st = stoi(S.substr(2));
	while(st--){
		px = xh, py = yh;
		if(d == 'U'){
			yh++;
		}
		if(d == 'D'){
			yh--;
		}
		if(d == 'L'){
			xh--;
		}
		if(d == 'R'){
			xh++;
		}
		if(abs(xt - xh) > 1 || abs(yt - yh) > 1){
			xt = px, yt = py;
		}
		sl.insert({xt, yt});
	}
	
}

int dist(int i1, int i2, int j1, int j2){
	return abs(i1 - j1) + abs(i2 - j2);
}

set<pair<int, int>> ans2;
int ax[10], ay[10], apx[10], apy[10];
void part2(){
	char d = S[0];
	int st = stoi(S.substr(2));
	while(st--){
		for(int j = 0; j < 10; j++){
			apx[j] = ax[j];
			apy[j] = ay[j];
		}
		if(d == 'U'){
			ay[0]++;
		}
		if(d == 'D'){
			ay[0]--;
		}
		if(d == 'L'){
			ax[0]--;
		}
		if(d == 'R'){
			ax[0]++;
		}
		bool mvdiag = 0;
		for(int j = 1; j < 10; j++){
			if(abs(ax[j] - ax[j-1]) > 1 || abs(ay[j] - ay[j-1]) > 1){
				int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
				int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
				int mnv = 1e9, mni = 0;
				for(int k = 0; k < 8; k++){
					int cur = dist(ax[j]+dx[k], ay[j]+dy[k], ax[j-1], ay[j-1]);
					if(cur < mnv){
						mnv = cur;
						mni = k;
					}
				}
				ax[j] += dx[mni];
				ay[j] += dy[mni];
			}
		}
		/*for(int i = 0; i < 1j0; i++){
			moo << ax[i] << ' ' << ay[i] << endl;
		}
		moo << endl;*/
		ans2.insert({ax[9], ay[9]});
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	sl.insert({0, 0});
	while(getline(eat, S)){
		if(S.size() == 0) break;
		part1();
		part2();
	}
	moo << sl.size() << endl;
	moo << ans2.size() << endl;
	// solve();
	//moo << sum << endl;
}