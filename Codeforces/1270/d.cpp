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
    int N, K; cin >> N >> K; 
    map<pii, int> m;
    for(int i = 1; i <= K+1; i++){
        cout << "? ";
        for(int j = 1; j <= K+1; j++){
            if(i == j) continue;
            cout << j << " ";
        }
        cout << endl;
        int pos, apos; cin >> pos >> apos;
        m[make_pair(apos, pos)]++;
    }
    cout << "! " << m.rbegin()->second << endl;
    return 0;
}


