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
        string s; cin >> s;
        int N = (int)s.length();
        int bcnt = 0;
        int tlen = N;
        for(int i = N-1; i >= 0; i--){
            if(s[i] == 'A'){
                if(bcnt > 0){
                    bcnt--;
                    tlen -= 2;
                }
            }else{
                bcnt++;
            }
        }
        tlen -= (bcnt/2)*2;
        cout << tlen << endl;
    } 
    return 0;
}


