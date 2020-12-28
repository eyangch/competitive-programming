#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> x[200000];
int ans[200000];

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i].first;
        x[i].second = i+1;
    }
    sort(x, x+N, cmp);
    set<int> pos;
    for(int i = 0; i < N; i++){
        auto it = pos.upper_bound(x[i].second);
        if(it != pos.begin()){
            ans[x[i].second-1] = *(--it);
        }
        pos.insert(x[i].second);
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
