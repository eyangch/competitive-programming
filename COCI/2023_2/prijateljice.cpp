#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, K;
string Ls[100000], Zs[100000];
int L[100000], Z[100000];
map<string, int> cc;
int rcc[200050];
int tp[200050];
vector<int> lt[26];
bool f[2][26][2];
bool dp[200050];

bool alb(string a, string b){
	int mnL = min(a.length(), b.length());
	for(int i = 0; i < mnL; i++){
		if(a[i] < b[i]) return 1;
		if(a[i] > b[i]) return 0;
	}
	if(a.length() > b.length()) return 1;
	else return 0;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M;
	K = N+M;
	for(int i = 0; i < N; i++){
		eat >> Ls[i];
	}
	for(int i = 0; i < M; i++){
		eat >> Zs[i];
	}
	int ptrN = 0, ptrM = 0, ct = 0;
	while(true){
		if(ptrN == N && ptrM == M) break;
		string ns, ms;
		if(ptrN == N){
			ns = "~";
		}else{
			ns = Ls[ptrN];
		}
		if(ptrM == M){
			ms = "~";
		}else{
			ms = Zs[ptrM];
		}
		bool x = (ns < ms);
		if(x){
			// ns is smaller
			cc[ns] = ct;
			tp[ct] = 0;
			rcc[ct++] = ns[0] - 'a';
			assert(ns[0] != '~');
			ptrN++;
		}else{
			// ms is smaller
			cc[ms] = ct;
			tp[ct] = 1;
			rcc[ct++] = ms[0] - 'a';
			assert(ms[0] != '~');
			ptrM++;
		}
	}
	/*for(int i = 0; i < N; i++){
		moo << cc[Ls[i]] << endl;
	}
	for(int i = 0; i < M; i++){
		moo << cc[Zs[i]] << endl;
	}*/
	for(int i = 0; i < N; i++){
		L[i] = cc[Ls[i]];
	}
	for(int i = 0; i < N; i++){
		Z[i] = cc[Zs[i]];
	}
	for(int i = K-1; i >= 0; i--){
		lt[rcc[i]].push_back(i);
	}
	// 0 = L win
	// 1 = Z win
	for(int i = 25; i >= 0; i--){
		int pi = i-1;
		if(i == 0) pi = 25;
		for(int j : lt[i]){
			int t = tp[j];
			if(f[t][i][!t] == 1){
				dp[j] = 0;
				f[!t][i][!t] = 1;
				f[!t][pi][!t] = 1;
			}else{
				dp[j] = 1;
				f[!t][i][t] = 1;
				f[!t][pi][t] = 1;
			}
			/*if(f[t][i][0] == 0 && f[t][i][1] == 0){
				dp[j] = 1;
			}else if(f[t][i][t] == 1 && f[t][i][!t] == 0){
				dp[j] = 1;
			}*/
			//moo << i << ' ' << j << ' ' << dp[j] << endl;
		}
	}
	moo << (dp[L[0]] ? "Leona" : "Zoe") << endl;
}