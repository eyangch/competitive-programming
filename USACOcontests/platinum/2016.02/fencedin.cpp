/*
Solution: O(N+M log(N+M))
Do some funny Kruskal stuff (notice how many edges are of same length)
We can remove all edges (fences) of same length as once because of how Kruskal's works.
*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

int A, B, N, M;
vector<int> f1, f2;
vector<pair<int, int>> g;
int rem[2];

int32_t main(){
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    cin >> A >> B >> N >> M;
    f1.push_back(0);
    f1.push_back(A);
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        f1.push_back(x);
    }
    f2.push_back(0);
    f2.push_back(B);
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        f2.push_back(x);
    }
    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());
    for(int i = 1; i < (int)f1.size(); i++){
        g.push_back({f1[i] - f1[i-1], 0});
    }
    for(int i = 1; i < (int)f2.size(); i++){
        g.push_back({f2[i] - f2[i-1], 1});
    }
    sort(g.begin(), g.end());
    bool found1 = false, found2 = false;
    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < (int)g.size(); i++){
        if(g[i].second == 0 && !found1){
            found1 = true, idx1 = i;
            break;
        }
    }
    int ans = (g[idx1].first * M), cnt = 0;
    g.erase(g.begin() + idx1);
    for(int i = 0; i < (int)g.size(); i++){
        if(g[i].second == 1 && !found2){
            found2 = true, idx2 = i;
            break;
        }
    }
    ans += (g[idx2].first * N);
    g.erase(g.begin() + idx2);
    rem[0] = N;
    rem[1] = M;
    for(pair<int, int> i : g){
        int len = i.first, dir = i.second;
        int addamt = rem[!dir];
        if(addamt <= 0) continue;
        cnt += addamt, ans += addamt * len;
        rem[dir]--;
        if(cnt >= (N+1)*(M+1)-1) break;
    }
    cout << ans << endl;
}
