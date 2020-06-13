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
        int p[n];
        for(int i = 0; i < n; i++){
            cin >> p[i];   
        }
        vi caps;
        caps.push_back(0);
        for(int i = 1; i < n-1; i++){
            if((p[i] > p[i-1] && p[i] > p[i+1]) || (p[i] < p[i-1] && p[i] < p[i+1])){
                caps.push_back(i);
            }
        }
        caps.push_back(n-1);
        cout << caps.size() << endl;
        for(int i = 0; i < (int)caps.size(); i++){
            cout << p[caps[i]] << " ";
        }cout << endl;
    }
    return 0;
}


