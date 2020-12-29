#include <bits/stdc++.h>

using namespace std;

int N, a, b;
int x[200000];
long long sumv[200001];

signed main(){
    cin >> N >> a >> b;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    long long ans = LLONG_MIN;
    multiset<long long> sums;
    sumv[0] = 0;
    if(a == 1) sums.insert(sumv[0]);
    for(int i = 0; i < N; i++){
        if(i > 0) sumv[i+1] = sumv[i];
        sumv[i+1] += x[i];
        if(i >= a-1){
            ans = max(ans, sumv[i+1] - (*sums.begin()));
        }
        if(i-a+2 >= 0){
            sums.insert(sumv[i-a+2]);
        }
        if(i-b+1 >= 0){
            sums.erase(sums.find(sumv[i-b+1]));
        }
    }
    cout << ans << endl;
}
