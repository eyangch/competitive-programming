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
    int N, P; cin >> N >> P;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    sort(a, a+N);
    vi good;
    for(int i = 0; i <= 2000; i++){
        int mp = 0;
        for(int j = 0; j < N; j++){
            if(a[j] >= i){
                break;
            }
            mp++;
        }
        bool bgood = true;
        for(int j = 0; j < N; j++){
            mp += upper_bound(a, a+N, i+j) - lower_bound(a, a+N, i+j);
            if(mp < 0 || mp % P == 0){
                bgood = false;
                break;
            }
            mp--;
        }
        if(bgood) good.push_back(i);
    }
    cout << good.size() << endl;
    for(int i : good) cout << i << " ";
    cout << endl;
    return 0;
}


