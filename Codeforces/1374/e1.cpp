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
    int N, K; cin >> N >> K;
    vi oo, oz, zo;
    oo.push_back(0);
    oz.push_back(0);
    zo.push_back(0);
    for(int i = 0; i < N; i++){
        int a, b, c; cin >> a >> b >> c;
        if(b == 1 && c == 1){
            oo.push_back(a);
        }else if(b == 1){
            oz.push_back(a);
        }else if(c == 1){
            zo.push_back(a);
        }
    } 
    sort(oo.begin(), oo.end());
    sort(oz.begin(), oz.end());
    sort(zo.begin(), zo.end());
    for(int i = 1; i < oo.size(); i++) oo[i] += oo[i-1];
    for(int i = 1; i < oz.size(); i++) oz[i] += oz[i-1];
    for(int i = 1; i < zo.size(); i++) zo[i] += zo[i-1];
    int ans = INT_MAX;
    for(int i = 0; i <= min(K, (int)oo.size()-1); i++){
        if(oz.size() > K-i && zo.size() > K-i){
            ans = min(ans, oo[i] + oz[K-i] + zo[K-i]);
        }
    }
    if(ans == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}


