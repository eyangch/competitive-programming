/*
ID: sireric1
LANG: C++11
TASK: fence
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
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

void ecircuit(int node, multiset<int> (&graph)[500], vi &res){
    if(graph[node].size() == 0){
        res.push_back(node);
    }else{
        while((int)graph[node].size() > 0){
            int nnode = *graph[node].begin();
            graph[node].erase(graph[node].find(nnode));
            graph[nnode].erase(graph[nnode].find(node));
            ecircuit(nnode, graph, res);
        }
        res.push_back(node);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int F; cin >> F;
    multiset<int> graph[500]; 
    for(int i = 0; i < F; i++){
        int u, v; cin >> u >> v;
        graph[u-1].insert(v-1);
        graph[v-1].insert(u-1);
    }
    int start = 0;
    for(int i = 0; i < 500; i++){
        if((int)graph[i].size() % 2 == 1){
            start = i;
            break;
        }
    }
    vi res;
    for(int i = start; i < 500; i++){
        multiset<int> cgraph[500];
        copy(graph, graph+500, cgraph);
        res.clear();
        ecircuit(i, cgraph, res);
        if((int)res.size() == F+1){
            break;
        }
    }
    reverse(res.begin(), res.end());
    for(int i : res){
        cout << i+1 << endl;
    }
    return 0;
}


