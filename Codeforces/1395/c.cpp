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
    int N, M; cin >> N >> M;
    int a[N], b[M];
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }
    for(int i = 0; i <= 512; i++){
        bool good = true;
        for(int j = 0; j < N; j++){
            int tgood = false;
            for(int k = 0; k < M; k++){
                if(((a[j]&b[k])|i) == i){
                    tgood = true;
                    break;
                }
            }
            if(!tgood){
                good = false;
                break;
            }
        }
        if(good){
            cout << i << endl;
            break;
        }
    }
    return 0;
}


