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
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

ll N, M, K, S, P[1000005], Ap, Bp, Cp, Dp, Q[1000005], Aq, Bq, Cq, Dq;

bool works(ll mid){
    ll lptr = 0;
    for(ll i = 0; i < N; i++){
        if(lptr >= M) return true;
        ll distmv = max(0LL, P[i] - Q[lptr]);
        ll left = mid;
        if(distmv > 0){
            if(distmv > left){
                return false;
            }else{
                while(lptr < M && Q[lptr] < P[i]){
                    lptr++;
                }
            }
        }
        while(lptr < M && left >= min(Q[lptr] - P[i], distmv) * 2 + max(Q[lptr] - P[i], distmv)){
            lptr++;
        }
    }
    if(lptr >= M){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("b.in", "r", stdin);
    ofstream fout("b.txt");
    ll T; cin >> T;
    for(ll tc = 1; tc <= T; tc++){
        cout << "Starting Testcase " << tc << endl;
        cin >> N >> M >> K >> S;
        for(ll i = 0; i < K; i++){
            cin >> P[i];
        }
        cin >> Ap >> Bp >> Cp >> Dp;
        for(ll i = 0; i < K; i++){
            cin >> Q[i];
        }
        cin >> Aq >> Bq >> Cq >> Dq;
        for(ll i = K; i < N; i++){
            P[i] = ((Ap*P[i-2] + Bp*P[i-1] + Cp) % Dp) + 1;
        }
        for(ll i = K; i < M; i++){
            Q[i] = ((Aq*Q[i-2] + Bq*Q[i-1] + Cq) % Dq) + 1;
        }
        sort(P, P+N);
        sort(Q, Q+M);
        cout << "Finish Processing Input" << endl;
        ll lo = 0;
        ll hi = INT_MAX;
        ll mid = 0;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(works(mid)){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        while(works(mid)){
            mid--;
        }
        while(!works(mid)){
            mid++;
        }
        cout << "Finish Binary Searching" << endl;
        fout << "Case #" << tc << ": " << mid << endl;
    }
    return 0;
}


