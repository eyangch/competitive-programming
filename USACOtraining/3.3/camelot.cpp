/*
ID: sireric1
LANG: C++11
TASK: camelot
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

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int dx2[8] = {0 , 0, 1,-1, 1, 1, -1, -1};
int dy2[8] = {-1, 1, 0, 0, 1, -1, -1, 1};

int p2i(pii x){
    return 31*x.first + x.second;
}

int p2i(int a, int b){
    return 31 * a + b;
}

pii i2p(int x){
    return pii(x/31, x%31);
}

vector<int> genLocs(int loc, int R, int C, bool k){
    vector<int> ans;
    if(k){
        for(int i = 0; i < 8; i++){
            int nx = loc/31+dx[i], ny = loc%31+dy[i];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C){
                continue;
            }
            ans.push_back(nx*31 + ny);
        }
    }else{
        for(int i = 0; i < 8; i++){
            int nx = loc/31+dx2[i], ny = loc%31+dy2[i];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C){
                continue;
            }
            ans.push_back(nx*31 + ny);
        }
    }
    return ans;
}

void bfs(int R, int C, int loc, bool k, int (&dist)[26][30]){
    fill(dist[0], dist[R-1]+C, 10000);
    queue<pair<int, int>> q;
    q.push(make_pair(loc, 0));
    while(!q.empty()){
        int nloc = q.front().first;
        int d = q.front().second;
        q.pop();
        int x = nloc/31, y = nloc%31;
        if(dist[x][y] != 10000) continue;
        dist[x][y] = d;
        vector<int> nxts = genLocs(nloc, R, C, k);
        for(int i : nxts){
            q.push(make_pair(i, d+1));
        }
    }
}

int distki[2][26][30];
int dist[26][30][26][30];
int distkn[780][26][30];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout); 
    int R, C; cin >> C >> R;
    char chsq;
    int nsq;
    cin >> chsq >> nsq;
    vector<int> king;
    king.push_back(p2i((int)chsq - 'A', nsq-1));
    vector<int> knights;
    while(cin >> chsq >> nsq){
        knights.push_back(p2i((int)chsq - 'A', nsq-1));
    }
    bfs(R, C, king[0], false, distki[0]);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            bfs(R, C, p2i(i, j), true, dist[i][j]);
        }
    }
    for(int i = 0; i < (int)knights.size(); i++){
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(int j = 0; j < R; j++){
            for(int k = 0; k < C; k++){
                 distkn[i][j][k] = dist[knights[i]/31][knights[i]%31][j][k] + distki[0][j][k];
                 pq.push(make_pair(distkn[i][j][k], j*31 + k));
                 distkn[i][j][k] = SHRT_MAX;
            }
        }
        distkn[i][pq.top().second/31][pq.top().second%31] = pq.top().first;
        while(!pq.empty()){
            int d = pq.top().first;
            int loc = pq.top().second;
            pq.pop();
            if(distkn[i][loc/31][loc%31] < d) continue;
            vector<int> nxtlocs = genLocs(loc, R, C, true);
            d++;
            for(int j : nxtlocs){
                int x = j/31;
                int y = j%31;
                if(distkn[i][x][y] <= d) continue;
                distkn[i][x][y] = d;
                pq.push(make_pair(d, j));
            }
        }
    }
    int ans = SHRT_MAX;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int tdist = distki[0][i][j];
            for(int k = 0; k < (int)knights.size(); k++){
                tdist += dist[knights[k]/31][knights[k]%31][i][j];
            }
            int ftdist = tdist;
            for(int k = 0; k < (int)knights.size(); k++){
                ftdist = min(ftdist, tdist - distki[0][i][j] - dist[knights[k]/31][knights[k]%31][i][j] + distkn[k][i][j]);
            }
            ans = min(ans, ftdist);
        }
    }
    cout << ans << endl;
    return 0;
}


