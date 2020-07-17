/*
ID: sireric1
LANG: C++11
TASK: ratios
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
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w" ,stdout);
    int t[3]; cin >> t[0] >> t[1] >> t[2];
    int mix[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3;j++){
            cin >> mix[i][j];
        }
    }
    int minN = INT_MAX;
    int minans[4];
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            for(int k = 0; k < 100; k++){
                int abc[3];
                abc[0] = i * mix[0][0] + j * mix[1][0] + k * mix[2][0];
                abc[1] = i * mix[0][1] + j * mix[1][1] + k * mix[2][1];
                abc[2] = i * mix[0][2] + j * mix[1][2] + k * mix[2][2];
                bool d[3];
                for(int x = 0; x < 3; x++) d[x] = (t[x] == 0);
                if((d[0] || abc[0] % t[0] == 0) && (d[1] || abc[1] % t[1] == 0) && (d[2] || abc[2] % t[2] == 0)){
                    bool good = true;
                    for(int x = 0; x < 3; x++){
                        if(abc[x] != 0 && t[x] == 0) good = false;
                        for(int y = x+1; y < 3; y++){
                            if(t[x] == 0 || t[y] == 0) continue;
                            if(abc[x] / t[x] != abc[y] / t[y] || abc[x]/t[x] == 0) good = false;
                        }
                    }
                    if(good && i + j + k < minN){
                        minN = i + j + k;
                        minans[0] = i;
                        minans[1] = j;
                        minans[2] = k;
                        minans[3] = max(abc[0], max(abc[1], abc[2])) / max(t[0], max(t[1], t[2]));
                    }
                }
            }
        }
    }
    if(minN == INT_MAX){
        cout << "NONE" << endl;
    }else{
        cout << minans[0] << " " << minans[1] << " " << minans[2] << " " << minans[3] << endl;
    }
    return 0;
}


