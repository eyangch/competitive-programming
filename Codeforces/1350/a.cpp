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
        int n, k; cin >> n >> k;
        if(n % 2 == 1){
            int add = n;
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0){
                    add = i;
                    break;
                }
            }
            n += add;
            k--;
        }
        cout << n + k * 2 << endl;
    }
    return 0;
}

