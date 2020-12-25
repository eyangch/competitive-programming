#include <bits/stdc++.h>

using namespace std;

int N;
int a[300];
int sum = 0;
vector<int> dp[100001];
bool vis[100001];

bool solve(int mid){
    int csum = 0;
    for(int i = 0; i < N; i++){
        if(mid - a[i] <= sum/2){
            csum += a[i];
        }
    }
    if(csum >= mid){
        return true;
    }else{
        return false;
    }
}

bool solve2(int mid){
    fill(vis, vis+mid+1, false);
    vis[0] = true;
    for(int i = 0; i < N; i++){
        if(mid - a[i] > sum/2){
            continue;
        }
        for(int j = mid; j >= 0; j--){
            if(j >= a[i] && !vis[j] && vis[j-a[i]]){
                vis[j] = true;
            }
        }
    }
    return vis[mid];
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum += a[i];
    }
    int lo = 0, hi = sum, mid = 0;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        if(solve(mid)){
            lo = mid+1;    
        }else{
            hi = mid-1;
        }
    }
    while(solve(mid)){
        mid++;
    }
    mid--;
    while(!solve2(mid)){
        mid--;
    }
    fill(vis, vis+mid+1, false);
    vis[0] = true;
    for(int i = 0; i < N; i++){
        if(mid - a[i] > sum/2){
            continue;
        }
        for(int j = mid; j >= 0; j--){
            if(j >= a[i] && !vis[j] && vis[j-a[i]]){
                dp[j] = dp[j-a[i]];
                dp[j].push_back(i+1);
                vis[j] = true;
            }
        }
    }
    cout << dp[mid].size() << endl;
    for(int i : dp[mid]){
        cout << i << " ";
    }
    cout << endl;
}
