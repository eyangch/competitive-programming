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
    int N; cin >> N;
    cout << 8 + (7 * N) << endl;
    cout << 0 << " " << 0 << endl;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(k == j) continue;
                cout << 2 * i + k << " " << 2 * i + j << endl;
            }
        }
        cout << 2 * (i+1) << " " << 2 * (i+1) << endl;
    }
    return 0;
}


