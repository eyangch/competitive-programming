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
    string s1, s2, s; cin >> s1 >> s2 >> s;
    int letters[26];
    fill(letters, letters + 26, 0);
    for(int i = 0; i < s1.length(); i++){
        letters[(int)(s1[i]) - 65]++;
    }
    for(int i = 0; i < s2.length(); i++){
        letters[(int)(s2[i]) - 65]++;
    }
    for(int i = 0; i < s.length(); i++){
        letters[(int)(s[i]) - 65]--;
    }
    for(int i = 0; i < 26; i++){
        if(letters[i] != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

