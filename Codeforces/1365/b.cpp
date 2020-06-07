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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pii a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i].first;   
        }
        for(int i = 0; i < n; i++){
            cin >> a[i].second;
        }
        int asrt = true;
        bool adif = false;
        int dif1 = a[0].second;
        for(int i = 0; i < n; i++){
            if(a[i].second != dif1) adif = true;
            if(i > 0 && a[i].first < a[i-1].first) asrt = false;
        }
        if(asrt || adif){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}


