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
    int n; cin >> n; 
    vector<int> nodes[n];
    bool minusone[n];
    fill(minusone, minusone + n, false);
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        if(p == -1){
            minusone[i] = true;
            continue;
        }
        nodes[p-1].push_back(i);
    }
    int maxcycle = 1;
    for(int i = 0; i < n; i++){
        if(!minusone[i]) continue;
        queue<pii> bfs;
        bfs.push(pii(i, 1));
        while(!bfs.empty()){
            pii idx = bfs.front();
            bfs.pop();
            maxcycle = max(maxcycle, idx.second);
            for(int j : nodes[idx.first]){
                bfs.push(pii(j, idx.second + 1));
            }
        }
    }
    cout << maxcycle << endl;
    return 0;
}


