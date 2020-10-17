#include <bits/stdc++.h>
#define f first
#define s second

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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        string s; cin >> s;
        bool good = true;
        for(int i = 0; i < N; i++){
            if(s[i] != '-' && s[i] != '>'){
                good = false; 
            }
        }
        if(good){
            cout << N << endl;
            continue;
        }
        good = true;
        for(int i = 0; i < N; i++){
            if(s[i] != '-' && s[i] != '<'){
                good = false; 
            }
        }
        if(good){
            cout << N << endl;
            continue;
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(s[i] == '-' || s[(i+1)%N] == '-'){
                ans++;
            }
        }
        cout << ans << endl;
    } 
    return 0;
}


