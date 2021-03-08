#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, K, occ[26];
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K >> s;
        if(N % K){
            moo << -1 << endl;
            continue;
        }
        fill_n(occ, 26, 0);
        int mx = -1;
        for(int i = 0; i < N; i++){
            int req = 0;
            for(int j = 0; j < 26; j++){
                if(occ[j] % K){
                    req += K - occ[j] % K;
                }
            }
            if(N - i >= req){
                bool ok = false;
                if(N - i - req >= K && s[i] != 'z'){
                    ok = true;
                }
                for(int j = s[i] - 'a'+1; j < 26; j++){
                    if(occ[j] % K) ok = true;
                }
                if(ok){
                    mx = i;
                }
            }
            occ[s[i]-'a']++;
        }
        int req = 0;
        for(int j = 0; j < 26; j++){
            if(occ[j] % K){
                req += K - occ[j] % K;
            }
        }
        if(!req){
            moo << s << endl;
            continue;
        }
        if(mx == -1){
            moo << -1 << endl;
            continue;
        }
        moo << s.substr(0, mx);
        fill_n(occ, 26, 0);
        for(int i = 0; i < mx; i++){
            occ[s[i]-'a']++;
        }
        req = 0;
        for(int i = 0; i < 26; i++){
            if(occ[i] % K){
                req += K - occ[i] % K;
            }
        }
        if(N - mx - req >= K){
            moo << (char)(s[mx]+1);
            occ[s[mx]+1-'a']++;
        }else{
            for(int i = s[mx] + 1 - 'a'; i < 26; i++){
                if(occ[i] % K){
                    moo << (char)('a'+i);
                    occ[i]++;
                    break;
                }
            }
        }
        req = 0;
        for(int i = 0; i < 26; i++){
            if(occ[i] % K) req += K - occ[i] % K;
        }
        for(int i = mx+1; i < N-req; i++){
            moo << 'a';
        }
        for(int i = N-req; i < N; i++){
            int nchar = 0;
            for(int j = 0; j < 26; j++){
                if(occ[j] % K){
                    nchar = j;
                    occ[j]++;
                    break;
                }
            }
            moo << (char)(nchar+'a');
        }
        moo << endl;
    }
}
