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
    int k;
    string s;
    cin >> k >> s;
    int letters[26];
    fill(letters, letters + 26, 0);
    for(char i : s){
        letters[(int)(i) - 97]++;   
    }
    for(int i = 0; i < 26; i++){
        if(letters[i] % k != 0){
            cout << -1 << endl;
            return 0;
        }
    }
    string basestring;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < letters[i] / k; j++){
            basestring += (char)(i) + 97;
        }
    }
    for(int i = 0; i < k; i++){
        cout << basestring;
    }cout << endl;
    return 0;
}


