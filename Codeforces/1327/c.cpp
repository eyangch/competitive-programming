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
    int N, M, K; cin >> N >> M >> K;
    for(int i = 0; i < 2 * K; i++){
        int x; cin >> x >> x;   
    }
    string s;
    for(int i = 0; i < N-1; i++) s += 'U';
    for(int i = 0; i < M-1; i++) s += 'L';
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N-1; j++) s += (i % 2 == 0 ? 'D' : 'U');
        s += 'R';
    }
    cout << s.length()-1 << endl << s.substr(0, s.length()-1) << endl;
    return 0;
}


