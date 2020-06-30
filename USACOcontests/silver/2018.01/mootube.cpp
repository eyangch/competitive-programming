#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define FOR(i, a, b) for(int i = (a); i < (b); i++)

typedef pair<int, int> pii;

bool visited[5000];

int dfs(int N, vector<pii> rel[5000], int K, int v){
    if(visited[v])
        return 0;
    visited[v] = true;
    int ret = 1;
    FOR(i, 0, (int)(rel[v].size())){
        if(rel[v][i].second < K)
            continue;
        ret += dfs(N, rel, K, rel[v][i].first);
    }
    return ret;
}

int main(){
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    vector<pii> rel[5000];
    int N, Q;
    fin >> N >> Q;
    FOR(i, 0, N - 1){
        int a, b, c;
        fin >> a >> b >> c;
        rel[a-1].pb(make_pair(b-1, c));
        rel[b-1].pb(make_pair(a-1, c));
    }
    FOR(i, 0, Q){
        int k, v;
        fin >> k >> v;
        fill(visited, visited + N, false);
        fout << dfs(N, rel, k, v-1) - 1 << endl;
    }
    return 0;
}
