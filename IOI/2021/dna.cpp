#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout

using namespace std;

int pfx[3][3][100000];

void init(string a, string b){
	for(int i = 0; i < (int)a.length(); i++){
		int ai = 0, bi = 0;
		if(a[i] == 'T') ai = 1;
		if(a[i] == 'C') ai = 2;
		if(b[i] == 'T') bi = 1;
		if(b[i] == 'C') bi = 2;
		pfx[ai][bi][i]++;
		if(i > 0){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k++){
					pfx[j][k][i] += pfx[j][k][i-1];
				}
			}
		}
	}
}

int get_distance(int x, int y){
	int d = 0;
	int cur[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cur[i][j] = pfx[i][j][y];
			if(x > 0) cur[i][j] -= pfx[i][j][x-1];
		}
	}
	for(int i = 0; i < 3; i++){
		int nxt = (i+1)%3;
		int mn = min(cur[i][nxt], cur[nxt][i]);
		d += mn;
		cur[i][nxt] -= d;
		cur[nxt][i] -= d;
	}
	int rem = cur[0][1] - cur[1][0];
	if(cur[1][2] - cur[2][1] != rem || cur[2][0] - cur[0][2] != rem){
		return -1;
	}
	return d + abs(rem) * 2;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	init("ATACAT", "ACTATA");
	moo << get_distance(1, 2) << ' ' << get_distance(4, 5) << ' ' << get_distance(0, 0) << endl;
}