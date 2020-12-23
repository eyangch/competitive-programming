#include <bits/stdc++.h>

using namespace std;

int N, D, M;
vector<int> day[100000];

vector<vector<int>> works(int t){
    vector<vector<int>> ret;
    queue<int> q, q2;
    for(int i = 0; i < N; i++){
        for(int j : day[i]){
            q.push(j);
            q2.push(i);
        }
        vector<int> today;
        for(int j = 0; j < t && !q.empty(); j++){
            today.push_back(q.front());
            q.pop();
            q2.pop();
        }
        if(!q2.empty() && q2.front() + D <= i){
            ret.clear();
            return ret;
        }
        ret.push_back(today);
    }
    if(!q.empty()){
        ret.clear();
    }
    return ret;
}

signed main(){
    cin >> N >> D >> M;
    for(int i = 0; i < M; i++){
        int x; cin >> x;
        day[x-1].push_back(i+1);
    }
    int lo = 0;
    int hi = 100000;
    int mid = 0;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        if(works(mid).empty()){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    while(works(mid).empty()){
        mid++;
    }
    vector<vector<int>> ans = works(mid);
    cout << mid << endl;
    for(vector<int> i : ans){
        for(int j : i){
            cout << j << " ";
        }
        cout << 0 << endl;
    }
}
