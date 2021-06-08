#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N;

bool sub(int item, char a, char b, char c, string &s){
    for(int i = 0; i < N - item + 1; i++){
        bool ok = true;
        if(s[i] != a) ok = false;
        if(item > 1 && s[i+1] != b) ok = false;
        if(item > 2 && s[i+2] != c) ok = false;
        if(ok) return false;
    }
    return true;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        string s; eat >> s;
        bool found = false;
        // one letter
        for(char i = 'a'; i <= 'z'; i++){
            if(sub(1, i, 'a', 'a', s)){
                found = true;
                moo << i << endl;
                break;
            }
        }
        if(found) continue;
        for(char i = 'a'; i <= 'z'; i++){
            for(char j = 'a'; j <= 'z'; j++){
                if(sub(2, i, j, 'a', s)){
                    found = true;
                    moo << i << j << endl;
                    break;
                }
            }
            if(found) break;
        }
        if(found) continue;
        for(char i = 'a'; i <= 'z'; i++){
            for(char j = 'a'; j <= 'z'; j++){
                for(char k = 'a'; k <= 'z'; k++){
                    if(sub(3, i, j, k, s)){
                        found = true;
                        moo << i << j << k << endl;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) break;
        }
        assert(found == true);
    }
}
