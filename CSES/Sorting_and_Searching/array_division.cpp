#include <bits/stdc++.h>

using namespace std;

int N, K;
int x[200000];

bool works(long long mid){
    int div = 0;
    long long sum = 0;
    for(int i = 0; i < N; i++){
        if(mid < x[i]) return false;
        if(sum + x[i] > mid){
            sum = x[i];
            div++;
        }else{
            sum += x[i];
        }
    }
    return (div < K);
}

signed main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    long long lo = 0, hi = 1e18, mid = 0;
    while(lo < hi){
        mid = (lo + (hi-lo)/2);
        if(works(mid)){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    while(works(mid)){
        mid--;
    }
    while(!works(mid)){
        mid++;
    }
    cout << mid << endl;
}
