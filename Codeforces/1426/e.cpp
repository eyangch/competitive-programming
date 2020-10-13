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

int N;
int a[3], b[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < 3;i++){
        cin >> a[i];
    }
    for(int i = 0; i < 3; i++){
        cin >> b[i];
    }
    int mx = 0, mn = N;
    for(int i = 0; i < 3; i++){
        mx += min(a[i], b[(i+1)%3]);
    }
    for(int i = 0; i < 3; i++){
        mn -= min(a[i], N-b[(i+1)%3]);
    }
    cout << mn << " " << mx << endl;
    return 0;
}


