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

ll S[1000005], X[1000005], Y[1000005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("a.in", "r", stdin);
    ofstream fout("a.txt");
    ll T; cin >> T; 
    for(ll tc = 1; tc <= T; tc++){
        cout << "STARTING TC: " << tc << endl;
        fout << "Case #" << tc << ": ";
        ll N, K; cin >> N >> K;
        for(ll i = 0; i < K; i++){
            cin >> S[i];
        }
        ll As, Bs, Cs, Ds; cin >> As >> Bs >> Cs >> Ds;
        for(ll i = 0; i < K; i++){
            cin >> X[i];
        }
        ll Ax, Bx, Cx, Dx; cin >> Ax >> Bx >> Cx >> Dx;
        for(ll i = 0; i < K; i++){
            cin >> Y[i];
        }
        ll Ay, By, Cy, Dy; cin >> Ay >> By >> Cy >> Dy;
        for(ll i = K; i < N; i++){
            S[i] = (As*S[i-2] + Bs*S[i-1] + Cs) % Ds;
            X[i] = (Ax*X[i-2] + Bx*X[i-1] + Cx) % Dx;
            Y[i] = (Ay*Y[i-2] + By*Y[i-1] + Cy) % Dy;
        }
        cout << "FINISH PROCESSING INPUT" << endl;
        ll totalp = 0, minp = 0, maxp = 0;
        for(ll i = 0; i < N; i++){
            totalp += S[i];
            minp += X[i];
            maxp += X[i] + Y[i];
        }
        cout << "FINISH IMPOSSIBLE CALC" << endl;
        if(totalp < minp || totalp > maxp){
            fout << -1 << endl;
            continue;
        }
        ll toohigh = 0, toolow = 0;
        for(ll i = 0; i < N; i++){
            if(S[i] > X[i] + Y[i]){
                toohigh += S[i] - (X[i] + Y[i]);
            }
            if(S[i] < X[i]){
                toolow += X[i] - S[i];
            }
        }
        cout << "FINISH LOW+HIGH CALC" << endl;
        fout << max(toohigh, toolow) << endl;
    }
    return 0;
}


