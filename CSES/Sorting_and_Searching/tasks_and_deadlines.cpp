#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> tasks[200000];

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tasks[i].first >> tasks[i].second;
    }
    sort(tasks, tasks+N);
    long long ans = 0, ctime = 0;
    for(int i = 0; i < N; i++){
        ctime += tasks[i].first;
        ans += tasks[i].second - ctime;
    }
    cout << ans << endl;
}
