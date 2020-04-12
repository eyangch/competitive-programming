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
        int n; cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];    
        }
        sort(a, a + n);
        stack<int> ans;
        for(int i = 0; i < n / 2; i++){
            ans.push(a[n - i - 1]);
            ans.push(a[i]);
        }
        if(n % 2 == 1){
            ans.push(a[n / 2]);
        }
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}


