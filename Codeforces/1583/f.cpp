#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K;
int ans[1000][1000];
int col[1000][20];

vector<int> cur, cnt;
int len = 1, n = 1;

void add(){
	while(!cnt.empty()){
		int x = cnt.back();
		cnt.pop_back();
		if(x != K-1){
			x++;
			cnt.push_back(x);
			break;
		}
	}
	if(cnt.empty()){
		if(len == n){
			len = 1;
			n++;
			cur.clear();
			cur.push_back(n);
		}else{
			while(true){
				int x = cur.back();
				cur.pop_back();
				if(cur.empty()){
					len++;
					cur.push_back(x);
					for(int i = len-1; i >= 1; i--){
						cur.push_back(i);
					}
					break;
				}
				x++;
				if(x < cur.back()){
					cur.push_back(x);
					for(int i = len-cur.size(); i >= 1; i--){
						cur.push_back(i);
					}
					break;
				}
			}
		}
	}
	while(cnt.size() < len){
		cnt.push_back(1);
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	cur.push_back(1);
	cnt.push_back(1);
	for(int i = 1; i < N; i++){
		/*for(int j : cur){
			moo << j << ' ';
		}
		moo << endl;
		for(int j : cnt){
			moo << j << ' ';
		}
		moo << endl << endl;*/
		for(int j = 0; j < len; j++){
			col[i][cur[j]] = cnt[j];
		}
		for(int j = 0; j < i; j++){
			for(int k = 0; k < len; k++){
				if(col[j][cur[k]] < cnt[k]){
					ans[j][i] = cur[k];
					break;
				}
			}
		}
		if(i != N-1) add();
	}
	moo << n << endl;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			moo << ans[i][j] << ' ';
		}
	}
	moo << endl;
}