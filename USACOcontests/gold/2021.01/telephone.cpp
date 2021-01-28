#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
typedef pair<int, int> pii;

int N, K;
int b[100000];
string s[100];

vector<int> loc[100];
int di[100000];

int dij(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    di[0] = 0;
    while(!pq.empty()){
        int id = pq.top().se, d = pq.top().fi;
        pq.pop();
        if(di[id] != d) continue;
        di[id] = d;
        if(s[b[id]][b[N-1]] == '1') return d;
        for(int i = 0; i < K; i++){
            if(s[b[id]][i] == '1'){
                for(int j : loc[i]){
                    int score = min(0LL, j-id);
                    if(di[id] - score < di[j]){
                        di[j] = di[id] - score;
                        pq.push({di[j], j});
                    }
                    if(j >= id) break;
                }
            }
        }
    }
    return -1;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >>b[i];
        b[i]--;
    }
    for(int i = 0; i < K; i++){
        cin >> s[i];
    }
    for(int i = 0; i < N; i++){
        loc[b[i]].push_back(i);
    }
    fill(di, di+N, 1e17);
    int ans = dij();
    if(ans == -1){
        cout << -1 << endl;
        return 0;
    }
    cout << N - 1 + ans * 2 << endl;
}
