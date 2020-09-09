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

ll N, A, B, K, ways[5000], pfx[5000], MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> A >> B >> K;
    A--;
    B--;
    ways[A] = 1;
    for(int i = A; i < N; i++){
        pfx[i]++;
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < B; j++){
            ways[j] = (pfx[(j+B-1)/2] - ways[j]) % MOD;
        }
        for(int j = B+1; j < N; j++){
            int idx = (j+B)/2;
            if(idx < 0){
                ways[j] = (pfx[N-1] - ways[j]) % MOD;
            }else{
                ways[j] = (pfx[N-1] - pfx[idx] - ways[j]) % MOD;
            }
        }
        pfx[0] = ways[0];
        for(int j = 1; j < N; j++){
            pfx[j] = pfx[j-1] + ways[j];
        }
    }
    cout << pfx[N-1] % MOD << endl;
    return 0;
}


