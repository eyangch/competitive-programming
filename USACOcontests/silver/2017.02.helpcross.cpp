#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int C, N;
    pair<int, int> cows[20000];
    map<int, int> chickentimes;
    cin >> C >> N;
    for(int i = 0; i < C; i++){
        int t;
        cin >> t;
        if(chickentimes.find(t) == chickentimes.end()){
            chickentimes.insert(make_pair(t, 1));
        }else{
            chickentimes[t]++;
        }
    }
    for(int i = 0; i < N; i++){
        cin >> cows[i].second >> cows[i].first;
    }
    sort(cows, cows + N);
    int ans = 0;
    for(int i = 0; i < N; i++){
        map<int, int>::iterator lowc = chickentimes.lower_bound(cows[i].second);
        if(lowc == chickentimes.end() || lowc->first > cows[i].first){
            continue;
        }
        if(lowc->second <= 1){
            chickentimes.erase(lowc);
        }else{
            lowc->second--;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
