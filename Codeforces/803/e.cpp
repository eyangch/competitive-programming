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
    int N, K; cin >> N >> K;
    string s; cin >> s;
    int mins[N], maxs[N];
    int rmin = 0, rmax = 0;
    for(int i = 0; i < N; i++){
        rmin = max(rmin, -K+1);
        rmax = min(rmax, K-1);
        if(rmin > rmax){
            cout << "NO" << endl;
            return 0;
        }
        mins[i] = rmin;
        maxs[i] = rmax;
        if(s[i] == 'L'){
            rmin--;
            rmax--;
        }else if(s[i] == 'W'){
            rmin++;
            rmax++;
        }else if(s[i] == 'D'){
        }else{
            rmin--;
            rmax++;
        }
    }
    int run = 0;
    char ansarr[N];
    if(rmin <= K && rmax >= K){
        run = K;
    }else if(rmin <= -K && rmax >= -K){
        run = -K;
    }
    if(run == 0){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = N-1; i >= 0; i--){
        if(s[i] != '?'){
            ansarr[i] = s[i];
            if(s[i] == 'L'){
                run++;
            }else if(s[i] == 'W'){
                run--;
            }
        }else{
            if(mins[i] <= run && maxs[i] >= run){
                ansarr[i] = 'D';
            }else if(mins[i] > run){
                run++;
                ansarr[i] = 'L';
            }else{
                run--;
                ansarr[i] = 'W';
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << ansarr[i];
    }
    cout << endl;
    return 0;
}


