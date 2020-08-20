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
    freopen("a.in", "r", stdin);
    ofstream fout("a.txt");
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cout << "Start tc " << tc << endl;
        int N, M, K; cin >> N >> M >> K;
        int A, B, R1, C1; cin >> A >> B >> R1 >> C1;
        bool x = (A+B)%2, y = (R1+C1)%2;
        fout << "Case #" << tc << ": ";
        if(K == 1) fout << "N" << endl;
        else{
            int R2, C2; cin >> R2 >> C2;
            bool z = (R2+C2)%2;
            if(x == y && y == z){
                fout << "Y" << endl;
            }else{
                fout << "N" << endl;
            }
        }
        cout << "End tc " << tc << endl;
    }
    return 0;
}


