#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, T;
int k[200000];

bool works(int mid){
    int prod = 0;
    for(int i = 0; i < N; i++){
        prod += mid/k[i];
        if(prod >= T) return true;
    }
    return false;
}

signed main(){
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        cin >> k[i];
    }
    int lo = 0, hi = LLONG_MAX, mid = 0;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        if(works(mid)){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    while(works(mid)) mid--;
    while(!works(mid)) mid++;
    cout << mid << endl;
}
