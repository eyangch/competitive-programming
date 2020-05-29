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
    bool bsieve[1001];
    fill(bsieve, bsieve + 1001, false);
    int leastdiv[1001];
    fill(leastdiv, leastdiv + 1001, -1);
    for(int i = 2; i < 1001; i++){
        for(int j = i; j < 1001; j+=i){
            if(leastdiv[j] == -1){
                leastdiv[j] = i;
            }
        }
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];   
        }
        map<int, int> color2div;
        int ccounter = 0;
        for(int i = 0; i < n; i++){
            if(color2div.find(leastdiv[a[i]]) == color2div.end()){
                ccounter++;
                color2div[leastdiv[a[i]]] = ccounter;
            }
        }
        cout << ccounter << endl;
        for(int i = 0; i < n; i++){
            cout << color2div[leastdiv[a[i]]] << " ";
        }
        cout << endl;
    }
    return 0;
}


