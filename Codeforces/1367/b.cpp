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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        int wrong[2];
        wrong[0] = wrong[1] = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];   
            if(i % 2 != a[i] % 2){
                wrong[i % 2]++;
            }
        }
        if(wrong[0] == wrong[1]){
            cout << wrong[0] << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}


