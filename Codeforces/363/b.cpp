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
    int n, k; cin >> n >> k;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >> h[i];   
    }
    int start = 0;
    for(int i = 0; i < k; i++){
        start += h[i];
    }
    int minstart = start, msidx = 1;
    for(int i = k; i < n; i++){
        start += h[i];
        start -= h[i - k];
        if(start < minstart){
            msidx = i - k + 2;
            minstart = start;
        }
    }
    cout << msidx << endl;
    return 0;
}


