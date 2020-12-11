#include <bits/stdc++.h>
#define f first
#define s second
//#define endl "\n"
#define int ll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {1, 0, -1, 1, 0, -1, -1, 1};

int N, M;
vector<string> b;
vector<string> b2;

int cnt(int x, int y){
    int ret = 0;
    for(int i = 0; i < 8; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M){
            continue;
        }
        if(b[nx][ny] == '#'){
            ret++;
        }
    }
    return ret;
}

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    vi a;
    while(cin >> nxt){
        b.push_back(nxt); 
    }
    N = (int)b.size();
    M = (int)b[0].size();
    bool o = true;
    b2 = b;
    while(o){
        o = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(b[i][j] == '#' && cnt(i, j) >= 4){
                    b2[i][j] = 'L';
                    o = true;
                }else if(b[i][j] == 'L' && !cnt(i, j)){
                    b2[i][j] = '#';
                    o = true;
                }
            }
        }
        b = b2;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(b[i][j] == '#') ans++;
        }
    }
    cout << ans << endl;
    return 0;
}



