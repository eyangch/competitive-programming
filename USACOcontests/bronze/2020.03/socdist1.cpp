#include <bits/stdc++.h>

using namespace std;

int N;
string s;

int32_t main(){
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);
    cin >> N >> s;
    vector<int> gaps;
    int prev = 0;
    for(; prev < N; prev++){
        if(s[prev] == '1') break;
    }
    for(int i = prev+1; i < N; i++){
        if(s[i] == '1'){
            gaps.push_back(i-prev);
            prev = i;
        }
    }
    sort(gaps.begin(), gaps.end(), greater<int>());
    int bside = 0, aside = 0;
    for(; bside < N && s[bside] == '0'; bside++){}
    for(; aside < N && s[N-1-aside] == '0'; aside++){}
    int minside = min(aside, bside);
    int maxside = max(aside, bside);
    int ans = 0;
    if(gaps.size() >= 1){
        ans = max(ans, min(gaps[gaps.size()-1], gaps[0]/3));
        ans = max(ans, min({gaps[gaps.size()-1], gaps[0]/2, maxside}));
    }
    if(gaps.size() >= 2){
        ans = max(ans, min(gaps[gaps.size()-1], gaps[1]/2));
    }
    if(minside == N){
        ans = max(ans, maxside-1);
    }else{
        ans = max({ans, minside, maxside/2});
    }
    cout << ans << endl;
}
