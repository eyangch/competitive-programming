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
        string s; cin >> s;
        int n0 = 0, n1 = 0;
        for(char i : s){
            if(i == '0') n0++;
            else n1++; 
        }
        if(n0 == 0 || n1 == 0){
            cout << s << endl;
        }else{
            for(int i = 0; i < (int)s.length(); i++){
                cout << "01";
            }cout << endl;
        }
    }
    return 0;
}


