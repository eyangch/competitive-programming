#include <bits/stdc++.h>

using namespace std;

int T, N, a[300000], stat[300000];

int test(int i){
    if(i == 0 || i == N-1) return 0;
    if(a[i] < a[i-1] && a[i] < a[i+1]){
        return 1;
    }
    if(a[i] > a[i-1] && a[i] > a[i+1]){
        return 1;
    }
    return 0;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        int hv = 0;
        for(int i = 1; i < N-1; i++){
            if(test(i) > 0){
                hv++;
            }
        }
        int ans = hv;
        for(int i = 1; i < N-1; i++){
            if(test(i) > 0){
                int csum = test(i-1) + test(i) + test(i+1);
                int og = a[i];
                a[i] = a[i-1];
                int diff = test(i-1) + test(i) + test(i+1) - csum;
                ans = min(ans, hv+diff);
                a[i] = a[i+1];
                diff = test(i-1) + test(i) + test(i+1) - csum;
                ans = min(ans, hv+diff);
                a[i] = og;
            }
        }
        cout << ans << endl;
    }
}
