/*
ID: sireric1
LANG: C++14
TASK: starry
*/

#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

struct dat{
	char let;
	vector<pair<int, int>> s;
};

int dx[] = {1, -1, 1, -1, 0, 0, -1, 1};
int dy[] = {1, 1, -1, -1, 1, -1, 0, 0};
int W, H;
string B[100];
bool vis[100][100], vis2[100][100];
char ans[100][101];
vector<pair<int, int>> pos;
char let = 'a';
vector<dat> D; 

void ff(int x, int y){
	if(x < 0 || y < 0 || x >= H || y >= W || vis[x][y] || B[x][y] == '0') return;
	vis[x][y] = 1;
	pos.push_back({x, y});
	for(int k = 0; k < 8; k++){
		int nx = x + dx[k], ny = y + dy[k];
		if(nx < 0 || ny < 0 || nx >= H || ny >= W || vis[nx][ny] || B[nx][ny] == '0') continue;
		ff(nx, ny);
	}
}

void ff2(int x, int y, char le){
	if(x < 0 || y < 0 || x >= H || y >= W || vis2[x][y] || B[x][y] == '0') return;
	//moo << "WOO" << x << ' ' << y << ' ' << le << endl;
	vis2[x][y] = 1;
	ans[x][y] = le;
	for(int k = 0; k < 8; k++){
		int nx = x + dx[k], ny = y + dy[k];
		if(nx < 0 || ny < 0 || nx >= H || ny >= W || vis2[nx][ny] || B[nx][ny] == '0') continue;
		ff2(nx, ny, le);
	}
}

void cvt(){
	int mnX = 1e15, mnY = 1e15, mxX = 0, mxY = 0;
	for(pair<int, int> i : pos){
		mnX = min(mnX, i.first);
		mxX = max(mxX, i.first);
		mnY = min(mnY, i.second);
		mxY = max(mxY, i.second);
	}
	/*vector<vector<bool>> res;
	res.resize(mxX - mnX + 1);
	for(vector<bool> &i : res){
		i.resize(mxY - mnY + 1);
	}
	for(pair<int, int> i : pos){
		int aX = i.first - mnX;
		int aY = i.second - mnY;
		res[aX][aY] = 1;
	}
	return res;*/
	for(pair<int, int> &i : pos){
		i.first -= mnX;
		i.second -= mnY;
	}
	sort(pos.begin(), pos.end());
}

void rot(){
	for(pair<int, int> &i : pos){
		swap(i.first, i.second);
		i.first = -i.first;
		//i.second = -i.second;
	}
}

void flip(){
	for(pair<int, int> &i : pos){
		i.first = -i.first;
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	freopen("starry.in", "r", stdin), freopen("starry.out", "w", stdout);
	eat >> W >> H;
	for(int i = 0; i < H; i++){
		eat >> B[i];
	}
	for(int i = 0; i < H; i++){
		fill(ans[i], ans[i]+W, '0');
	}
	auto sf = [](dat a, dat b){
		for(int n = 0; n < min(a.s.size(), b.s.size()); n++){
			if(a.s[n] < b.s[n]) return true;
			if(a.s[n] > b.s[n]) return false;
		}
		return a.s.size() < b.s.size();
	};
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(vis[i][j] || B[i][j] == '0') continue;
			pos.clear();
			ff(i, j);
			vector<pair<int, int>> cv[8];
			for(int k = 0; k < 4; k++){
				cvt();
				cv[2*k] = pos;
				flip();
				cvt();
				cv[2*k+1] = pos;
				flip();
				rot();
			}
			int fidx = -1;
			for(int k = 0; k < 8; k++){
				//moo << "Done " << i << ' ' << j << ' ' << k << endl; moo.flush();
				dat x = {'a', cv[k]};
				int id = lower_bound(D.begin(), D.end(), x, sf) - D.begin();
				if(id >= D.size()){
					continue;
				}
				bool yuh = 0;
				if(D[id].s.size() == cv[k].size()){
					yuh = 1;
					for(int l = 0; l < cv[k].size(); l++){
						if(D[id].s[l] != cv[k][l]){
							yuh = 0;
							break;
						}
					}
				}
				if(yuh){
					fidx = id;
					break;
				}
			}
			//moo << "Done " << i << ' ' << j << endl; moo.flush();
			char clet = 0;
			if(~fidx){
				clet = D[fidx].let;
			}else{
				//moo << "UHOH" << endl; moo.flush();
				clet = let++;
				//moo << "INC: " << i << ' ' << j << endl;
				for(int k = 0; k < 8; k++){
					dat p = {clet, cv[k]};
					D.push_back(p);
				}
				//moo << "UHOH2 " << i << ' ' << j << endl; moo.flush();
				sort(D.begin(), D.end(), sf);
			}
			ff2(i, j, clet);
			//moo << "Done " << i << ' ' << j << endl; moo.flush();
			/*moo << "PRINTING D: " << endl;
			for(dat cd : D){
				moo << cd.let << endl;
				for(pair<int, int> pt : cd.s){
					moo << pt.first << ' ' << pt.second << endl;
				}
				moo << endl;
			}*/
		}
	}
	for(int i = 0; i < H; i++){
		moo << ans[i] << endl;
	}
}