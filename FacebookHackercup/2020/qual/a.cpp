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
    freopen("a.txt", "w", stdout);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N; cin >> N;
        string si, so; cin >> si >> so;
        string adj[N];
        for(int i = 0; i < N; i++){
            string curr (N, 'N');
            curr[i] = 'Y';
            for(int j = i+1; j < N; j++){
                if(so[j-1] == 'N' || si[j] == 'N') break;
                curr[j] = 'Y';
            }
            for(int j = i-1; j >= 0; j--){
                if(so[j+1] == 'N' || si[j] == 'N') break;
                curr[j] = 'Y';
            }
            adj[i] = curr;
        }
        cout << "Case #" << tc << ":" << endl;
        for(int i = 0; i < N; i++){
            cout << adj[i] << endl;
        }
    }
    return 0;
}


