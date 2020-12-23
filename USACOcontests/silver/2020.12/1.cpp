#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[100000];

signed main(){
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        int children = graph[i].size();
        if(i == 0) children++;
        int dupes = ceil(log2(children));
        ans += dupes + children-1;
    }
    cout << ans << endl;
}
