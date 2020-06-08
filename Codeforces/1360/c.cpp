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
        int a[n]; 
        for(int i = 0; i < n; i++){
            cin >> a[i];   
        }
        int odd = 0, even = 0;
        sort(a, a+n);
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 0){
                even++;
            }else{
                odd++;
            }
        }
        bool p = false;
        for(int i = 1; i < n; i++){
            if(a[i] - a[i-1] == 1) p = true;
        }
        if(odd % 2 != even % 2 || (odd % 2 == 1 && !p)){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}


