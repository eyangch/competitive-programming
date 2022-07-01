#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, pfx[10], sfx[10];
string s;

string sub1(string c, int cL){
	int carry = 1;
	for(int i = cL-1; i >= 0; i--){
		c[i] -= carry;
		carry = 0;
		if(c[i] < '0'){
			carry = 1;
			c[i] = '9';
		}
	}
	return c;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> s;
		fill(pfx, pfx+10, 0);
		fill(sfx, sfx+10, 0);
		N = s.length();
		s = sub1(s, N);
		if(sub1(s, N)[0] == '0'){
			for(int i = 0; i < N-2; i++){
				moo << 9;
			}
			moo << endl;
			continue;
		}
		for(int i = 0; i < N; i++){
			pfx[s[i]-'0']++;
		}
		bool wow = 1;
		for(int i = 0; i < 10; i++){
			if(pfx[i] & 1){
				wow = 0;
				break;
			}
		}
		if(wow){
			moo << s << endl;
			continue;
		}
		string ans = "";
		for(int i = N-1; i >= 0; i--){
			pfx[s[i]-'0']--;
			int nbad = 0;
			bool hasbl = 0;
			for(int j = 0; j < 10; j++){
				if(pfx[j] & 1){
					if(j < s[i]-'0' && !hasbl){
						hasbl = 1;
						continue;
					}
					nbad++;
				}
			}
			int rem = N-1-i;
			if(rem < nbad || s[i] == '0'){
				continue;
			}
			for(int j = 0; j < i; j++){
				moo << s[j];
			}
			int lstd = s[i]-'0'-1;
			for(; lstd >= 0; lstd--){
				int baddies = 0;
				pfx[lstd]++;
				for(int j = 0; j < 10; j++){
					if(pfx[j] & 1){
						baddies++;
					}
				}
				if(baddies <= rem){
					break;
				}
				pfx[lstd]--;
			}
			moo << lstd;
			string tag = "";
			for(int j = i+1; j < N; j++){
				bool miss = false;
				for(int k = 0; k < 10; k++){
					if(pfx[k] & 1){
						miss = true;
						tag += (char)('0' + k);
						pfx[k]--;
						break;
					}
				}
				if(miss) continue;
				tag += '9';
			}
			reverse(tag.begin(), tag.end());
			moo << tag << endl;
			break;
		}
	}
}