#include <bits/stdc++.h>

using namespace std;

int N, K;
pair<int, int> movies[200000];

bool ccmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int32_t main(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &movies[i].first, &movies[i].second);
    }
    sort(movies, movies+N, ccmp);
    multiset<int> members;
    for(int i = 0; i < K; i++){
        members.insert(-1);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        auto it = members.upper_bound(movies[i].first);
        if(it == members.begin()) continue;
        it--;
        members.erase(it);
        members.insert(movies[i].second);
        ans++;
    }
    printf("%d\n", ans);
}
