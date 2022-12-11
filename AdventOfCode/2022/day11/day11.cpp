#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M;
string S;
int ans[20];
int mk = 0;
vector<int> itm[20];
int op[20];
int pr[20];
int ni[20];
int dv[20];
int tr[20], fs[20];
int MOD = 1;

void part1(){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j <= mk; j++){
			for(int k : itm[j]){
				int nk = k;
				if(op[j] == 2){
					nk *= k;
				}
				if(op[j] == 1){
					nk *= pr[j];
				}
				if(op[j] == 0){
					nk += pr[j];
				}
				nk /= 3;
				int add = tr[j];
				if(nk % dv[j]){
					add = fs[j];
				}
				itm[add].push_back(nk);
				ans[j]++;
			}
			itm[j].clear();
		}
	}
}

void part2(){
	for(int i = 0; i < 10000; i++){
		for(int j = 0; j <= mk; j++){
			for(int k : itm[j]){
				int nk = k;
				if(op[j] == 2){
					nk *= k;
				}
				if(op[j] == 1){
					nk *= pr[j];
				}
				if(op[j] == 0){
					nk += pr[j];
				}
				nk %= MOD;
				//nk /= 3;
				int add = tr[j];
				if(nk % dv[j]){
					add = fs[j];
				}
				itm[add].push_back(nk);
				ans[j]++;
			}
			itm[j].clear();
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	while(getline(eat, S, ' ')){
		//moo << "OK: " << S << endl;
		if(S.size() && S[0] == '~') break;
		if(S == "Monkey"){
			getline(eat, S, ':');
			mk = stoi(S);
			getline(eat, S);
			getline(eat, S);
			S = S.substr(18);
			for(int i = 0; i < S.size(); i += 4){
				string cur = S.substr(i, i+2);
				itm[mk].push_back(stoi(cur));
			}
			getline(eat, S); // Op
			S = S.substr(23);
			//moo << S << endl;
			if(S[0] == '*'){
				if(S[2] == 'o'){
					op[mk] = 2;
				}else{
					op[mk] = 1;
					pr[mk] = stoi(S.substr(2));
				}
			}else{
				op[mk] = 0;
				pr[mk] = stoi(S.substr(2));
			}
			getline(eat, S); // Test
			S = S.substr(21);
			dv[mk] = stoi(S);
			MOD *= dv[mk];
			getline(eat, S); // tru
			S = S.substr(29);
			//moo << S << endl;
			tr[mk] = stoi(S);
			getline(eat, S); // false
			S = S.substr(30);
			//moo << S << endl;
			fs[mk] = stoi(S);
			getline(eat, S);
		}
	}
	part2();
	sort(ans, ans+mk+1);
	moo << ans[mk] * ans[mk-1] << endl;
	//moo << cyc << endl;
	// solve();
	//moo << sum << endl;
}