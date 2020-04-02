#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        ll N, K; cin >> N >> K;
        ll a[N];
        set<ll> useK;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        bool out = true;
        for(int i = 0; i < N; i++){
            set<ll> curruse;
            while(a[i] != 0){
                ll lg = 0;
                while(pow(K, lg) <= a[i]){
                    lg++;
                }
                lg--;
                if(useK.find(lg) != useK.end() || curruse.find(lg) != curruse.end()){

                    out = false;
                    break;
                }
                curruse.insert(lg);
                a[i] -= pow(K, lg);
            }
            if(!out){
                break;
            }
            for(set<ll>::iterator it = curruse.begin(); it != curruse.end(); it++){
                useK.insert(*it);
            }
        }
        if(out) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
