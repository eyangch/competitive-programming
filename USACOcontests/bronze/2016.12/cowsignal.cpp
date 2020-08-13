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
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int M, N, K; cin >> M >> N >> K;
    string b[M];
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }
    for(int i = 0; i < M; i++){
        string linetk;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < K; k++){
                linetk += b[i][j];
            }
        }
        for(int j = 0; j < K; j++){
            cout << linetk << endl;
        }
    }
    return 0;
}


