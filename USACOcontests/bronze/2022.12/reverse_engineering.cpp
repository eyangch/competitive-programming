#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;
multimap<string, int> A;

bool uwu(int bit, char st){
	int cbit = -1;
	for(auto it = A.begin(); it != A.end(); it++){
		string s = it->first;
		int x = it->second;
		if(s[bit] == st){
			if(cbit == -1 || cbit == x){
				cbit = x;
			}else{
				return 0;
			}
		}
	}
	if(cbit == -1) return 0;
	return 1;
}

void rm(int bit, char st){
	vector<pair<string, int>> rmv;
	for(pair<string, int> p : A){
		if(p.first[bit] == st){
			rmv.push_back(p);
		}
	}
	for(auto s : rmv){
		A.erase(A.find(s.first));
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> M;
		A.clear();
		for(int i = 0; i < M; i++){
			string s;
			int x;
			eat >> s >> x;
			A.insert({s, x});
		}
		bool ok = 1;
		while(A.size()){
			int bit = -1;
			char st;
			for(int i = 0; i < N && !~bit; i++){
				bool a = uwu(i, '0');
				bool b = uwu(i, '1');
				if(a){
					bit = i;
					st = '0';
				}
				if(b){
					bit = i;
					st = '1';
				}
			}
			if(!~bit){
				ok = 0;
				break;
			}
			rm(bit, st);
		}
		if(ok){
			moo << "OK" << endl;
		}else{
			moo << "LIE" << endl;
		}
	}
}