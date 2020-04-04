#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> v){for(T i : v) os << i << " ";}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << " ";}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl;}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}

