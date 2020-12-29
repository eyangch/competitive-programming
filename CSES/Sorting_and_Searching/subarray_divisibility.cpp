#include <bits/stdc++.h>

using namespace std;

int N;
int a[200000];
int vis[200000];

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a[i] %= N;
    }
    long long sum = 0, ans = 0;
    vis[0] = 1;
    for(int i = 0; i < N; i++){
        sum = (sum + a[i] + N) % N;
        ans += vis[sum]++;
    }
    cout << ans << endl;
}
