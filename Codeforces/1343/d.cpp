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
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];    
        }
        int adda[n / 2], mina[n / 2], maxa[n / 2];
        int line[k * 2 + 1000];
        fill(line, line + k * 2 + 1000, 0);
        for(int i = 0; i < n / 2; i++){
            adda[i] = a[i] + a[n - 1 - i];
            mina[i] = adda[i] - (max(a[i], a[n - 1 - i]) - 1);
            maxa[i] = adda[i] + k - (min(a[i], a[n - 1 - i]));
            line[adda[i]]++;
            line[adda[i]+1]--;
            line[mina[i]]++;
            line[maxa[i]+1]--;
        }
        int mv = 0;
        int add = 0;
        for(int i = 0; i < k * 2 + 1000; i++){
            add += line[i];
            mv = max(mv, add);
        }
        cout << n - mv << endl;
    }
    return 0;
}


