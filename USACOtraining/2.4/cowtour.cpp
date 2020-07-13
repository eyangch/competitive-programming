/*
ID: sireric1
LANG: C++11
TASK: cowtour
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
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    int N; cin >> N;
    double x[150], y[150];
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];   
    }
    string adjS[N];
    for(int i = 0; i < N; i++){
        cin >> adjS[i];
    }
    double dist[150][150];
    fill(dist[0], dist[N-1]+N, INT_MAX);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(adjS[i][j] == '1'){
                dist[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            }else if(i == j){
                dist[i][j] = 0;
            }
        }
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N;i ++){
            for(int j = 0; j < N; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    double maxDist[150];
    fill(maxDist, maxDist+N, 0);
    double maxmaxDist = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dist[i][j] == INT_MAX) continue;
            maxDist[i] = max(maxDist[i], dist[i][j]);
        }
        maxmaxDist = max(maxmaxDist, maxDist[i]);
    }
    double ans = INT_MAX;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dist[i][j] < INT_MAX){
                continue;
            }
            ans = min(ans, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) + maxDist[i] + maxDist[j]);
        }
    }
    cout << fixed << setprecision(6) << max(maxmaxDist, ans) << endl;
    return 0;
}


