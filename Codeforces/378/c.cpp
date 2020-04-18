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

int main(){
    int n, m, k; cin >> n >> m >> k;
    string b[n];
    int reached = 0;
    for(int i = 0; i < n; i++){
        cin >> b[i];  
        for(int j = 0; j < m; j++){
            if(b[i][j] == '.'){
                b[i][j] = 'X';  
                reached++; 
            }
        }
    }
    queue<pii> bfs;
    for(int i = 0; i < n * m; i++){
        int x = i / m;
        int y = i % m;
        if(b[x][y] == 'X'){
            bfs.push(pii(x, y));
            break;
        }
    }
    while(!bfs.empty()){
        pii idx = bfs.front();
        bfs.pop();
        if(idx.f < 0 || idx.f > n-1 || idx.s < 0 || idx.s > m-1 || b[idx.f][idx.s] != 'X'){
            continue;
        }
        if(reached <= k){
            break;
        }
        reached--;
        b[idx.f][idx.s] = '.';
        bfs.push(pii(idx.f + 1, idx.s));
        bfs.push(pii(idx.f - 1, idx.s));
        bfs.push(pii(idx.f, idx.s + 1));
        bfs.push(pii(idx.f, idx.s - 1));
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << endl;
    }
    return 0;
}


