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
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N, M; cin >> N >> M;
    string s[N];
    string p[N];
    for(int i = 0; i < N; i++){
        cin >> s[i];   
    }
    for(int i = 0; i < N; i++){
        cin >> p[i];
    }
    int ans = 0;
    bool sg[64];
    int cmap[100];
    cmap[(int)'A'] = 0;
    cmap[(int)'C'] = 1;
    cmap[(int)'G'] = 2;
    cmap[(int)'T'] = 3;
    for(int i = 0; i < M; i++){
        for(int j = i+1; j < M; j++){
            for(int k = j+1; k < M; k++){
                fill(sg, sg+64, false);
                for(int l = 0; l < N; l++){
                    sg[cmap[(int)s[l][i]] * 16 + cmap[(int)s[l][j]] * 4 + cmap[(int)s[l][k]] * 1] = true;
                }
                bool good = true;
                for(int l = 0; l < N; l++){
                    if(sg[cmap[(int)p[l][i]] * 16 + cmap[(int)p[l][j]] * 4 + cmap[(int)p[l][k]] * 1]){
                        good = false;
                        break;
                    }
                }
                if(good){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


