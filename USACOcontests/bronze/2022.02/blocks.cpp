#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int N, perm[4];
string b[4];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> b[0] >> b[1] >> b[2] >> b[3];
    for(int i = 0; i < N; i++){
        string s; eat >> s;
        bool good = false;
        iota(perm, perm+4, 0);
        do{
            for(int j = 0; j < (int)s.size(); j++){
                good = false;
                for(char c : b[perm[j]]){
                    if(c == s[j]){
                        good = true;
                    }
                }
                if(!good) break;
            }
            if(good){
                break;
            }
        }while(next_permutation(perm, perm+4));
        moo << (good ? "YES" : "NO") << endl;
    }
}
