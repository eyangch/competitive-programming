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
        int n, x; cin >> n >> x;
        int a[n];
        int total = 0;
        bool divx[n];
        int cntdivx = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];   
            total += a[i];
            divx[i] = (a[i] % x == 0);
            cntdivx += !divx[i];
        }
        if(total % x != 0){
            cout << n << endl;
        }else{
            int si = n;
            for(int i = 0;i < n; i++){
                if(!divx[i] || !divx[n-i-1]){
                    si = i;
                    break;
                }
            }
            cout << n - si - 1 << endl;
        }
    }
    return 0;
}


