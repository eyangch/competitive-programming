#include <bits/stdc++.h>

using namespace std;

int N, X;
int a[200000];

signed main(){
    cin >> N >> X;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    int lo = 0, hi = 0;
    int sum = 0, ans = 0;
    for(; lo < N; lo++){
        while(sum < X){
            sum += a[hi++];
        }
        ans += (sum == X);
        sum -= a[lo];
    }
    cout << ans << endl;
}
