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

vi graphd[200000], graphu[200000];

vi topsort(int N, vi (&graph)[200000]){
    vi ret(N, -1);
    int indeg[N];
    fill(indeg, indeg+N, 0);
    for(int i = 0; i < N; i++){
        for(int j : graph[i]){
            indeg[j]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < N; i++){
        if(indeg[i] == 0){
            q.push(i);
            //cout << "Qi PUSH: " << i << endl;
        }
    }
    int order = 0;
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        for(int i : graph[idx]){
            indeg[i]--;
            if(indeg[i] == 0){
                q.push(i);
                //cout << "Q PUSH: " << i << endl;
            }
        }
        ret[idx] = order;
        order++;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N, M; cin >> N >> M;
        for(int i = 0; i < N; i++){
            graphd[i].clear();
            graphu[i].clear();
        }
        for(int i = 0; i < M; i++){
            int t, u, v; cin >> t >> u >> v;
            if(t){
                graphd[u-1].push_back(v-1);
            }else{
                graphu[u-1].push_back(v-1);
                graphu[v-1].push_back(u-1);
            }
        }
        vi tsort = topsort(N, graphd);
        bool good = true;
        for(int i : tsort){
            if(i == -1) good = false;
        }
        if(good){
            cout << "YES" << endl;
            for(int i = 0; i < N; i++){
                for(int j : graphu[i]){
                    if(i < j) continue;
                    int a = i, b = j;
                    if(tsort[a] > tsort[b]){
                        swap(a, b);
                    }
                    cout << a+1 << " " << b+1 << endl;
                }
                for(int j : graphd[i]){
                    cout << i+1 << " " << j+1 << endl;
                }
            }
        }else{
            cout << "NO" << endl;
        }
        //cout << tsort << endl;
    }
    return 0;
}


