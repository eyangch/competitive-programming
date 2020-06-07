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
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];   
    }
    pii b[n];
    int bi[n];
    for(int i = 0; i < n; i++){
        cin >> bi[i];
        b[i].first = bi[i];
        b[i].second = i;
    }
    sort(b, b + n);
    sort(bi, bi + n);
    int dist[n];
    for(int i = 0; i < n; i++){
        dist[i] = b[a[i]-1].second - i;
        if(dist[i] < 0){
            dist[i] += n;
        }
        //cout << dist[i] << endl;
    }
    map<int, int> frq;
    for(int i = 0; i < n; i++){
        frq[dist[i]]++;
    }
    int mcount = 0;
    for(auto i : frq){
        mcount = max(mcount, i.second);
    }
    cout << mcount << endl;
    return 0;
}


