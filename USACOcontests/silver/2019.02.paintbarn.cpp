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
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k; cin >> n >> k;
    int pdiff[1001][1001];
    fill(pdiff[0], pdiff[1000] + 1001, 0);
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for(int j = y1; j < y2; j++){
            pdiff[x1][j]++;
            pdiff[x2][j]--;
        }
    }
    int ans = 0;
    for(int i = 0; i < 1001; i++){
        int cnt = 0;
        for(int j = 0; j < 1001; j++){
            cnt += pdiff[j][i];
            if(cnt == k){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}


