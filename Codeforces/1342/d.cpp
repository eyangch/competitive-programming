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
    int n, k; cin >> n >> k;
    int m[n], c[k];
    for(int i = 0; i < n; i++){
        cin >> m[i];   
    }
    for(int i = 0; i < k; i++){
        cin >> c[i];
    }
    sort(m, m + n);
    int mg = 0;
    int curr = 0;
    for(int i = n-1; i >= 0; i--){
        curr++;
        mg = max(mg, curr / c[m[i]-1] + (curr % c[m[i]-1] != 0));
    }
    cout << mg << endl;
    for(int i = 0; i < mg; i++){
        cout << (n - i) / mg + ((n-i) % mg != 0) << " ";
        for(int j = i; j < n; j += mg){
            cout << m[j] << " ";
        }cout << endl;
    }
    return 0;
}


