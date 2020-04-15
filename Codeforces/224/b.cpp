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
    int n, k; cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];    
    }
    map<int, int> d;
    int stop = 0;
    for(int i = 0; i < n && (int)d.size() < k; i++){
        if(d.find(a[i]) != d.end()){
            d.insert(pii(a[i], 0));
        }
        d[a[i]]++;
        stop = i;
    }
    int start = 1;
    for(int i = 0; i < n; i++){
        if(d.find(a[i]) != d.end() && d[a[i]] > 1){
            start = i + 2;
            d[a[i]]--;
        }else{
            break;
        }
    }
    if((int)d.size() == k){
        cout << start << " " << stop + 1 << endl;
    }else{
        cout << "-1 -1" << endl;
    }
    return 0;
}


