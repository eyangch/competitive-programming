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
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N; cin >> N;
        bitset<64> a[N];
        for(int i = 0; i < N; i++){
            int x; cin >> x;
            a[i] = bitset<64>(x);
        }
        int win = 1;
        for(int i = 50; i >= 0; i--){
            int ones = 0, zeros = 0;
            for(int j = 0; j < N; j++){
                ones += a[j][i];
                zeros += !a[j][i];
            }
            if(ones % 2 == 0) continue;
            if(ones % 4 == 3 && N % 2 == 1){
                win = 0;
                break;
            }else{
                win = 2;
                break;
            }
        }
        if(win == 2){
            cout << "WIN" << endl;
        }else if(win == 1){
            cout << "DRAW" << endl;
        }else{
            cout << "LOSE" << endl;
        }
    }
    return 0;
}


