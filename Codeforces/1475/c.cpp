#include <bits/stdc++.h>

using namespace std;

int T;
int A, B, K;
int a[200000], b[200000];
int amta[200000], amtb[200000];

int32_t main(){
    cin >> T;
    while(T--){
        cin >> A >> B >> K;
        for(int i = 0; i < A; i++){
            amta[i] = 0;
        }
        for(int i = 0; i < B; i++){
            amtb[i] = 0;
        }
        for(int i = 0; i < K; i++){
            cin >> a[i];
            a[i]--;
            amta[a[i]]++;
        }
        for(int i = 0; i < K; i++){
            cin >> b[i];
            b[i]--;
            amtb[b[i]]++;
        }
        long long ans = 0;
        for(int i = 0; i < K; i++){
            long long plus = K - amta[a[i]] - amtb[b[i]] + 1;
            ans += plus;
        }
        cout << ans / 2 << endl;
    }
}
