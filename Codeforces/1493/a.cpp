#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, K;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        vector<int> ans;
        for(int i = N; i > K; i--) ans.push_back(i);
        for(int i = K-1; 2 * i >= K; i--) ans.push_back(i);
        moo << ans.size() << endl;
        for(int i : ans) moo << i << " ";
        moo << endl;
    }
}
