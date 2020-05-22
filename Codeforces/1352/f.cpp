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
        int n[3]; cin >> n[0] >> n[1] >> n[2];
        if(n[0] > 0 && n[2] > 0){
            for(int i = 0; i < n[0] + 1; i++){
                cout << 0;
            }
            for(int i = 0; i < n[2] + 1; i++){
                cout << 1;
            }
            for(int i = 0; i < n[1] - 1; i++){
                cout << i % 2;
            }
        }else if(n[0] > 0){
            for(int i = 0; i < n[0] + 1; i++){
                cout << 0;
            }
            for(int i = 0; i < n[1]; i++){
                cout << (i % 2 == 0);
            }
        }else{
            for(int i = 0; i < n[2] + 1; i++){
                cout << 1;
            }
            for(int i = 0; i < n[1]; i++){
                cout << i % 2;
            }
        }
        cout << endl;
    }
    return 0;
}


