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
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N; cin >> N;
    int hi[25000], lo[25000], hi2[25000], lo2[25000];
    bool cards[100010];
    fill(cards, cards+100010, false);
    for(int i = 0; i < N/2; i++){
        cin >> hi[i];
        cards[hi[i]] = true;
    }
    for(int i = 0; i < N/2; i++){
        cin >> lo[i];
        cards[lo[i]] = true;
    }
    sort(hi, hi+N/2, greater<int>());
    sort(lo, lo+N/2);
    int idx = 1;
    for(int i = 0; i < N/2; i++){
        while(cards[idx]){
            idx++;
        }
        lo2[i] = idx;
        idx++;
    }
    for(int i = 0; i < N/2; i++){
        while(cards[idx]){
            idx++;
        }
        hi2[i] = idx;
        idx++;
    }
    reverse(hi2, hi2+N/2);
    idx = 0;
    int ans = 0;
    /*for(int i = 0; i < N/2; i++){
        cout << hi[i] << " " << hi2[i] << endl;
    }cout << endl;
    for(int i = 0; i < N/2; i++){
        cout << lo[i] << " " << lo2[i] << endl;
    }*/
    for(int i = 0; i < N/2; i++){
        if(hi[i] > hi2[idx]) continue;
        ans++;
        idx++;
    }
    idx = 0;
    for(int i = 0; i < N/2; i++){
        if(lo[i] < lo2[idx]) continue;
        ans++;
        idx++;
    }
    cout << ans << endl;
    return 0;
}


