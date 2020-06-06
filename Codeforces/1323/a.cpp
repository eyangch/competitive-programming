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
        vi even;
        vi odd;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            if(a % 2 == 0){
                even.push_back(i+1); 
            }else{
                odd.push_back(i+1);
            }  
        }
        if((int)even.size() > 0){
            cout << 1 << endl << even[0] << endl;
        }else if((int)odd.size() > 1){
            cout << 2 << endl << odd[0] << " " << odd[1] << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}


