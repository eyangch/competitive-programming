#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll L[1000005], H[1000005];
pair<pii, ll> delta[2000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const ll MOD = 1000000007LL;
    freopen("a1.in", "r", stdin);
    ofstream fout("a1.txt");
    ll T; cin >> T;
    for(ll tc = 1; tc <= T; tc++){
        ll N, K, W; cin >> N >> K >> W;
        cout << "Starting Testcase " << tc << endl;
        for(ll i = 0; i < K; i++){
            cin >> L[i];
        }
        ll Al, Bl, Cl, Dl; cin >> Al >> Bl >> Cl >> Dl;
        for(ll i = 0; i < K; i++){
            cin >> H[i];
        }
        ll Ah, Bh, Ch, Dh; cin >> Ah >> Bh >> Ch >> Dh;
        for(ll i = K; i < N; i++){
            L[i] = (Al*L[i-2] + Bl*L[i-1] + Cl) % Dl + 1LL;
            H[i] = (Ah*H[i-2] + Bh*H[i-1] + Ch) % Dh + 1LL;
        }
        for(ll i = 0; i < N; i++){
            delta[i] = make_pair(pii(L[i], H[i]), 1);
            delta[N+i] = make_pair(pii(L[i]+W, H[i]), -1);
        }
        sort(delta, delta+2*N);
        ll lx = L[0], ly = 0, ux = 0, uy = 0;
        ll ans = 1;
        ll prevperim = 0;
        multiset<ll> active;
        ll ptr = 0;
        cout << "Finish Preprocessing" << endl;
        for(ll i = 0; i < N; i++){
            while(ptr < 2*N && delta[ptr].first.first < L[i]){
                if(delta[ptr].second == 1){
                    active.insert(delta[ptr].first.second);
                }else{
                    active.erase(active.find(delta[ptr].first.second));
                }
                ptr++;
            }
            if(i == 0){
                ux = L[i]+W;
                uy = max(uy, H[i]);
            }else if(L[i] <= L[i-1]+W){
                if(H[i] > *active.rbegin()){
                    ll cmax = *active.rbegin();
                    prevperim -= 2LL * cmax;
                    ux = L[i];
                    prevperim += (ux - lx + uy - ly) * 2LL;
                    while(prevperim < 0){
                        prevperim += MOD;
                    }
                    prevperim %= MOD;
                    lx = L[i];
                    ux = L[i]+W;
                    uy = H[i];
                }else{
                    ux = L[i]+W;
                    uy = max(uy, H[i]);
                }
            }else{
                prevperim += (ux - lx + uy - ly) * 2LL;
                prevperim %= MOD;
                lx = L[i];
                ux = L[i]+W;
                uy = H[i];
            }
            ans *= ((prevperim) + (ux - lx + uy - ly) * 2LL) % MOD;
            ans %= MOD;
        }
        fout << "Case #" << tc << ": " << ans << endl;
        cout << "End Testcase " << tc << endl << endl;
    }
    return 0;
}


