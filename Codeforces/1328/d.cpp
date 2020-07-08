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
    while(T--){
        int N; cin >> N;
        int t[N];
        set<int> types;
        for(int i = 0; i < N; i++){
            cin >> t[i];   
            types.insert(t[i]);
        }
        if((int)types.size() == 1){
            cout << 1 << endl;
            for(int i = 0; i < N; i++){
                cout << 1 << " ";
            }cout << endl;
        }else if(N % 2 == 0 || t[0] == t[N-1]){
            cout << 2 << endl;
            for(int i = 0; i < N; i++){
                cout << (i%2) + 1 << " ";
            }cout << endl;
        }else{
            int rep = -1;
            for(int i = 1; i < N; i++){
                if(t[i] == t[i-1]){
                    rep = i;
                }
            }
            if(rep == -1){
                cout << 3 << endl;
                for(int i = 0; i < N/2; i++){
                    cout << "1 2 ";
                }
                cout << 3 << endl;
            }else{
                cout << 2 << endl;
                for(int i = 0; i < rep; i++){
                    cout << (i%2) + 1 << " ";
                }
                cout << (1 - (rep % 2)) + 1 << " ";
                for(int i = rep+1; i < N; i++){
                    cout << (1 - (i % 2)) + 1 << " ";
                }cout << endl;
            }
        }
    }
    return 0;
}


