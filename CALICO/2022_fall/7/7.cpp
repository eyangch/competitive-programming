#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;
vector<string> bad;
string S;
string vw[] = {"a", "e", "i", "o", "u"};
char lts[] = {'a', 'e', 'i', 'o', 'u',
			'm', 'n', 'p', 't', 'k', 's',
			'w', 'j', 'l'};

bool f(string x){
	if(S.find(x) != string::npos){
		return 1;
	}
	return 0;
}

bool isV(char x){
	for(int i = 0; i < 14; i++){
		if(lts[i] == x){
			if(i < 5) return 1;
			else return 0;
		}
	}
	assert(false);
	return 0;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	bad.push_back("wu");
	bad.push_back("wo");
	bad.push_back("ji");
	bad.push_back("ti");
	bad.push_back("nn");
	bad.push_back("nm");
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			bad.push_back(vw[i] + vw[j]);
		}
	}
	while(T--){
		eat >> S;
		N = S.size();
		bool ok = 1;
		for(char i : S){
			bool cf = 0;
			for(int j = 0; j < 14; j++){
				if(i == lts[j]) cf = 1;
			}
			if(!cf) ok = 0;
		}
		if(!ok){
			moo << "ike" << endl;
			continue;
		}
		for(string i : bad){
			if(f(i)) ok = 0;
		}
		if(!ok){
			moo << "ike" << endl;
			continue;
		}
		int stg = 0;
		for(int i = 0; i < N; i++){
			bool vt = isV(S[i]);
			if(!vt){
				if(stg == 1){
					ok = 0;
					break;
				}
				if(stg == 2){
					if(S[i] != 'n'){
						stg = 0;
					}
				}
				stg = (stg + 1) % 3;
			}else{
				stg = 2;
			}
		}
		if(ok && stg != 1){
			moo << "pona" << endl;
		}else{
			moo << "ike" << endl;
		}
	}
}