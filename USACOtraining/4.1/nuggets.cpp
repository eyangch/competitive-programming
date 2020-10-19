/*
ID: sireric1
LANG: C++11
TASK: nuggets
*/

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

int N, a[10];
bool pos[257];

int main(){
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        if(a[i] == 1){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 2; i <= 256; i++){
        bool good = true;
        for(int j = 0;j  < 10; j++){
            if(a[j] % i != 0){
                good = false;
                break;
            }
        }
        if(good){
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    pos[0] = true;
    for(int i = 0; true; i++){
        if(i - ans > 257){
            break;
        }
        if(pos[i%257]){
            pos[i%257] = false;
            for(int j = 0; j < N; j++){
                pos[(i%257+a[j])%257] = true;
                //cout << i << " " << i+a[j] << endl;
            }
        }else{
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}


