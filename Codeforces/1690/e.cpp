#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, a[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        int sum = 0;
        eat >> N >> K;
        for(int i = 0; i < N; i++){
            eat >> a[i];
            sum += a[i];
            a[i] %= K;
        }
        multiset<int> s;
        for(int i = 0; i < N; i++){
            s.insert(a[i]);
        }
        int sub = 0;
        while(!s.empty()){
            int l = *s.rbegin();
            s.erase(prev(s.end()));
            auto it = s.lower_bound(K-l);
            if(it == s.end()) it = s.begin();
            sub += (l + *it) % K;
            s.erase(it);
        }
        moo << (sum - sub) / K << endl;
    }
}
