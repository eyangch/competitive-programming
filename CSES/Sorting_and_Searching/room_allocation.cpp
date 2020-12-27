#include <bits/stdc++.h>

using namespace std;

int N;
pair<pair<int, int>, int> c[200000];
int ans[200000];
set<pair<int, int>> rooms;

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c[i].first.first >> c[i].first.second;
        c[i].second = i;
    }
    sort(c, c+N);
    rooms.insert({0, 1});
    for(int i = 0; i < N; i++){
        auto it = rooms.upper_bound({c[i].first.first, 0});
        if(it == rooms.begin()){
            ans[c[i].second] = rooms.size()+1;
            rooms.insert({c[i].first.second, ans[c[i].second]});
        }else{
            it--;
            ans[c[i].second] = (*it).second;
            rooms.erase(it);
            rooms.insert({c[i].first.second, ans[c[i].second]});
        }
    }
    cout << rooms.size() << endl;
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
