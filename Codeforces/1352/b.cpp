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
        int n, k; cin >> n >> k;
        if(k % 2 == 0 && n % 2 == 1){
            cout << "NO" << endl;   
        }else{
            if(k % 2 == n % 2){
                if(n - (k - 1) <= 0){
                    cout << "NO" << endl;
                    continue;
                }
                cout << "YES" << endl;
                cout << n - (k-1) << " ";
                for(int i = 0; i < k-1; i++){
                    cout << 1 << " ";
                }cout << endl;
            }else{
                if(n - 2 * (k - 1) <= 0){
                    cout << "NO" << endl;
                    continue;
                }
                cout << "YES" << endl;
                cout << n - 2 * (k - 1) << " ";
                for(int i = 0; i < k-1; i++){
                    cout << 2 << " ";
                }cout << endl;
            }
        }
    }
    return 0;
}


