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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        int a[N];
        for(int i = 0; i < N; i++){
            cin >> a[i];
            if(i % 2 == 0 && a[i] < 0){
                a[i] = -a[i];   
            }else if(i % 2 == 1 && a[i] > 0){
                a[i] = -a[i];
            }
        }
        for(int i = 0; i < N ;i++){
            cout << a[i] << " ";
        }cout << endl;
    }
    return 0;
}


