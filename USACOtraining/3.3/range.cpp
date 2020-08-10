/*
ID: sireric1
LANG: C++11
TASK: range
*/

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
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout); 
    int N; cin >> N;
    string f[N];
    for(int i = 0; i < N; i++){
        cin >> f[i];
    }
    int pfx[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            pfx[i][j] = (int)f[i][j] - '0';
            if(i > 0){
                pfx[i][j] += pfx[i-1][j];
            }
            if(j > 0){
                pfx[i][j] += pfx[i][j-1];
            }
            if(i > 0 && j > 0){
                pfx[i][j] -= pfx[i-1][j-1];
            }
        }
    }
    for(int i = 1; i < N; i++){
        int cnt = 0;
        for(int j = 0; j+i < N; j++){
            for(int k = 0; k+i < N; k++){
                int rct = pfx[j+i][k+i];
                if(j > 0){
                    rct -= pfx[j-1][k+i];
                }
                if(k > 0){
                    rct -= pfx[j+i][k-1];
                }
                if(j > 0 && k > 0){
                    rct += pfx[j-1][k-1];
                }
                if(rct == (i+1) * (i+1)){
                    cnt++;
                }
            }
        }
        if(cnt > 0){
            cout << i+1 << " " << cnt << endl;
        }
    }
    return 0;
}


