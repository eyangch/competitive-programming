#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;


void dij(int N, vector<pii> graph[100000], int src, int (&dist)[100000]){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    bool vis[N];
    fill(dist, dist+N, INT_MAX);
    fill(vis, vis+N, false);
    dist[src] = 0;
    pq.push(pii(dist[src], src));
    while(!pq.empty()){
        pii lst = pq.top();
        pq.pop();
        if(vis[lst.second]){
            continue;
        }
        vis[lst.second] = true;
        for(pii i : graph[lst.second]){
            if(dist[i.first] > dist[lst.second] + i.second){
                dist[i.first] = dist[lst.second] + i.second;
                pq.push(pii(dist[i.first], i.first));
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    /*
    (0) /6-(3)-0-(5)
     2 /          1
    (1)--3-(2)-1-(4)
    */
    int N = 6;
    vector<pii> graph[100000]; // (dest, dist)
    graph[0].push_back(pii(1, 2));
    graph[1].push_back(pii(0, 2));
    graph[1].push_back(pii(2, 3));
    graph[1].push_back(pii(3, 6));
    graph[2].push_back(pii(1, 3));
    graph[2].push_back(pii(4, 1));
    graph[3].push_back(pii(1, 6));
    graph[3].push_back(pii(5, 0));
    graph[4].push_back(pii(2, 1));
    graph[4].push_back(pii(5, 1));
    graph[5].push_back(pii(3, 0));
    graph[5].push_back(pii(4, 1));
    int dist[100000];
    dij(N, graph, 0, dist);
    for(int i = 0; i < N; i++){
        cout << "Distance from 0 -> " << i << ": " << dist[i] << endl;
    }
    return 0;
}


