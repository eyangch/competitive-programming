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
    int n; cin >> n;
    int a[n], sa[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];    
    }
    copy(a, a + n, sa);
    sort(sa, sa + n);
    vector<int> swaper;
    for(int i = 0; i < n && (int)swaper.size() < 2; i++){
        if(a[i] != sa[i]){
            swaper.push_back(i);
        }
    }
    if(swaper.size() < 2){
        cout << "YES" << endl;
    }else{
        swap(a[swaper[0]], a[swaper[1]]);
        for(int i = 0; i < n; i++){
            if(a[i] != sa[i]){
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}


