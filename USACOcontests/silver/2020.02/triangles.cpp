#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int N; cin >> N;
    vector<pii> hv[2][20001];
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b;
        hv[0][a+10000].push_back(make_pair(b+10000, i));
        hv[1][b+10000].push_back(make_pair(a+10000, i));
    }
    ll hvn[2][N];
    for(int ornt = 0; ornt < 2; ornt++){
        for(int i = 0; i < 20001; i++){
            if((int)hv[ornt][i].size() == 0){
                continue;
            }
            sort(hv[ornt][i].begin(), hv[ornt][i].end());
            ll startN = 0;
            ll delta = 0;
            for(pii j : hv[ornt][i]){
                startN += j.first - hv[ornt][i][0].first;
                delta--;
            }
            hvn[ornt][hv[ornt][i][0].second] = startN;
            for(int j = 1; j < (int)hv[ornt][i].size(); j++){
                delta += 2;
                startN += delta * (hv[ornt][i][j].first - hv[ornt][i][j-1].first);
                hvn[ornt][hv[ornt][i][j].second] = startN;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += hvn[0][i] * hvn[1][i];
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}


