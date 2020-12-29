#include <bits/stdc++.h>

using namespace std;

int N, X;
int a[200000];

signed main(){
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    map<long long, long long> sums;
    long long sum = 0, ans = 0;
    for(int i = 0; i < N; i++){
        sums[sum]++;
        sum += a[i];
        if(sums.count(sum-X)){
            ans += sums[sum-X];
        }
    }
    cout << ans << endl;
}
