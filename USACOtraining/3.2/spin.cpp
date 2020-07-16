/*
ID: sireric1
LANG: C++11
TASK: spin
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
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    pii whl[5];
    vector<pii> wedges[5];
    for(int i = 0; i < 5; i++){
        cin >> whl[i].second;
        whl[i].first = 0;
        int W; cin >> W;
        for(int j = 0; j < W; j++){
            pii x;
            cin >> x.first >> x.second;
            wedges[i].push_back(x);
        }
    }
    //for(int i = 0; i < 5; i++){
        //cout << whl[i] << endl << wedges[i] << endl << endl;
    //}
    for(int num = 0; true; num++){
        int through[360];
        fill(through, through+360, 0);
        for(int i = 0; i < 5; i++){
            for(pii j : wedges[i]){
                for(int k = 0; k <= j.second; k++){
                    through[(j.first+k+whl[i].first)%360]++;
                }
            }
        }
        for(int i : through){
            if(i == 5){
                cout << num << endl;
                return 0;
            }
        }
        for(int i = 0; i < 5; i++){
            whl[i].first += whl[i].second;
            whl[i].first %= 360;
        }
        bool good = true;
        for(int i = 0; i < 5; i++){
            if(whl[i].first != 0){
                good = false;
                break;
            }
        }
        if(good){
            cout << "none" << endl;
            return 0;
        }
    }
    return 0;
}


