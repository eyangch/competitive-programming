#include <bits/stdc++.h>
#define endl "\n"
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, Q, sieve[200001], mxpw[200001];
map<int, int> m[200001];
multiset<int> ex[200001];

int bpow(int x, int p){
    int ret = 1;
    for(int i = 0; i < 30; i++){
        if(p&(1LL<<i)){
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
    }
    return ret;
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> Q;
    for(int i = 2; i < 200001; i++){
        if(!sieve[i]){
            for(int j = i; j < 200001; j += i){
                sieve[j] = i;
            }
        }
    }
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        while(x > 1){
            m[i][sieve[x]]++;
            x /= sieve[x];
        }
        for(pair<int, int> j : m[i]){
            ex[j.first].insert(j.second);
        }
    }
    int ans = 1;
    for(int i = 0; i < 200001; i++){
        if((int)ex[i].size() == N){
            ans = ans * bpow(i, *ex[i].begin()) % MOD;
        }
    }
    while(Q--){
        int y, x; cin >> y >> x;
        y--;
        map<int, int> cur;
        while(x > 1){
            cur[sieve[x]]++;
            x /= sieve[x];
        }
        for(pair<int, int> i : cur){
            int prev = *ex[i.first].begin();
            if((int)ex[i.first].size() < N) prev = 0;
            if(m[y].count(i.first)){
                ex[i.first].erase(ex[i.first].find(m[y][i.first]));
            }
            m[y][i.first] += i.second;
            ex[i.first].insert(m[y][i.first]);
            int nxt = *ex[i.first].begin();
            if((int)ex[i.first].size() < N) nxt = 0;
            ans = ans * bpow(i.first, nxt - prev) % MOD;
        }
        moo << ans << endl;
    }
}
