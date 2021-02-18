#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int T, N, a[200000], sieve[200001], dp[200001];
unordered_set<int> f;

void get_factors(vector<int> &p){
    if(!p.size()) return;
    int x = p.back();
    p.pop_back();
    get_factors(p);
    f.insert(1);
    vector<int> add;
    for(int i : f){
        add.push_back(i * x);
    }
    for(int i : add){
        f.insert(i);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 2; i < 200001; i++){
        if(sieve[i]) continue;
        for(int j = i; j < 200001; j += i){
            sieve[j] = i;
        }
    }
    cin >> T;
    while(T--){
        for(int i = 0; i < 200001; i++){
            dp[i] = 0;
        }
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        sort(a, a+N);
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(i > 0 && a[i] == a[i-1]){
                dp[a[i]]++;
                continue;
            }
            vector<int> p;
            int x = a[i];
            while(true){
                if(!sieve[x]){
                    break;
                }
                p.push_back(sieve[x]);
                x /= sieve[x];
            }
            f.clear();
            get_factors(p);
            for(int j : f){
                dp[a[i]] = max(dp[a[i]], dp[j]);
            }
            dp[a[i]]++;
        }
        for(int i = 0; i < 200001; i++){
            ans = max(ans, dp[i]);
        }
        cout << N - ans << endl;
    }
}
