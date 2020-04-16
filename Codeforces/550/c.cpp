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
    string s; cin >> s;
    for(int i = 0; i < 1000; i += 8){
        string f = to_string(i);
        int search = -1;
        bool good = true;
        for(char j : f){
            search = s.find(j, search + 1);
            if(search == (int)string::npos){
                good = false;
                break;
            }
        }
        if(good){
            cout << "YES" << endl << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}


