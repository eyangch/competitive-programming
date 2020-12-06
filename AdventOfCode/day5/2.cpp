#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

bool ok[1024];

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    int ans =0;
    while(getline(cin, nxt)){
        int r = 0;
        for(int i = 0; i < 7; i++){
            if(nxt[i] == 'B'){
                r |= (1 << 7-i-1);
            }
        }
        int c = 0;
        for(int i = 7; i < 10; i++){
            if(nxt[i] == 'R'){
                c |= (1 << 10-i-1);
            }
        }
        ok[8*r+c] = true;
        //ans = max(ans, 8 * r + c);
    }
    for(int i = 1; i < 1023; i++){
        if(!ok[i] && (ok[i-1] && ok[i+1])){
            cout << i << endl;
        }
    }
    //cout << ans << endl;
    return 0;
}




