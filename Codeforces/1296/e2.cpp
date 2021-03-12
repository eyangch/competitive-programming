#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, c[200000];
string s;
set<pair<char, int>> t;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> s;
    for(int i = 0; i < N; i++){
        auto it = t.upper_bound({s[i], 1e7});
        if(it == t.begin()){
            c[i] = t.size()+1;
        }else{
            it--;
            c[i] = it->second;
            t.erase(it);
        }
        t.insert({s[i], c[i]});
    }
    moo << t.size() << endl;
    for(int i = 0; i < N; i++){
        moo << c[i] << " ";
    }
    moo << endl;
}
