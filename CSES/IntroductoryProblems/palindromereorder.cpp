#include <bits/stdc++.h>
#define f first
#define s second

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

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int N = (int)s.length();
    int c[26];
    fill(c, c+26, 0);
    for(int i = 0; i < N;i++){
        c[(int)s[i]-'A']++;
    }
    int total = 0;
    for(int i = 0; i < 26; i++){
        total += c[i];
    }
    int odd = -1;
    for(int i = 0; i < 26; i++){
        if(c[i] % 2 == 1 && odd != -1){
            cout << "NO SOLUTION" << endl;
            return 0;
        }else if(c[i] % 2 == 1){
            odd = i;
        }
    }
    if(odd != -1 && N % 2 != 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < c[i] / 2; j++){
            cout << (char)(i+'A');
            total++;
        }
    }
    if(odd != -1){
        cout << (char)(odd+'A');
    }
    for(int i = 25; i >= 0; i--){
        for(int j = 0; j < c[i] / 2; j++){
            cout << (char)(i+'A');
            total++;
        }
    }
    cout << endl;
    return 0;
}


