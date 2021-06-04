#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, a[2000];
vector<int> o, e;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        o.clear(), e.clear();
        eat >> N;
        for(int i = 0; i < N; i++){
            eat >> a[i];
            if(a[i] % 2) o.push_back(a[i]);
            else e.push_back(a[i]);
        }
        int ans = (int)o.size() * (int)e.size();
        for(int i = 0; i < (int)o.size(); i++){
            for(int j = i+1; j < (int)o.size(); j++){
                if(gcd(o[i], o[j]) > 1) ans++;
            }
        }
        for(int i = 0; i < (int)e.size(); i++){
            for(int j = i+1; j < (int)e.size(); j++){
                ans++;
            }
        }
        moo << ans << endl;
    }
}
