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
    freopen("b.in", "r", stdin);
    freopen("b.txt", "w", stdout);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N; cin >> N;
        string s; cin >> s;
        int ac = 0, bc = 0;
        for(int i = 0; i < N; i++){
            if(s[i] == 'A') ac++;
            else bc++;   
        }
        cout << "Case #" << tc << ": ";
        if(ac - bc == 1 || ac - bc == -1){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }
    return 0;
}


