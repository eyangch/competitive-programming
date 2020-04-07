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
    map<int, int> x;    
    int maxa = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        maxa = max(a, maxa);
        if(x.find(a) != x.end()){
            x[a]++;    
        }else{
            x.insert(pii(a, 1));
        }
    }
    int ans = 0;
    while(x.size() > 0){
        ans++;
        for(int accum = 0; accum < n; accum++){
             map<int, int>::iterator it = x.lower_bound(accum);
             if(it == x.end()){
                break;
             }
             it -> second--;
             if(it -> second <= 0){
                x.erase(it);
             }
        }
    }
    cout << ans << endl;
    return 0;
}


