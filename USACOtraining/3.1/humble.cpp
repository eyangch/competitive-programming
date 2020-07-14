/*
ID: sireric1
LANG: C++11
TASK: humble
*/

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
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    int K, N; cin >> K >> N;
    int p[K];
    for(int i = 0; i < K; i++){
        cin >> p[i];
    }
    int humble[N+1];
    humble[0] = 1;
    for(int i = 1; i <= N; i++){
        int minN = INT_MAX;
        for(int j = 0; j < K; j++){
            minN = min(minN, p[j] * (*upper_bound(humble, humble+i, humble[i-1] / p[j])));
        }
        humble[i] = minN;
    }
    cout << humble[N] << endl;
    return 0;
}


