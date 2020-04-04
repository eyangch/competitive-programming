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
    int a, b, c, d; cin >> a >> b >> c >> d;
    int misha = max(3 * a / 10, a - a / 250 * c);
    int vasya = max(3 * b / 10, b - b / 250 * d);
    if(misha > vasya){
        cout << "Misha" << endl;
    }else if(misha < vasya){
        cout << "Vasya" << endl;
    }else{
        cout << "Tie" << endl;
    }
    return 0;
}


