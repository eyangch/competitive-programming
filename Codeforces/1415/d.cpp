#include <bits/stdc++.h>
#define endl "\n"
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, a[100000], pfx[100001];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        pfx[i+1] = pfx[i] ^ a[i];
    }
    for(int i = 1; i < N-1; i++){
        int x = __builtin_clz(a[i-1]), y = __builtin_clz(a[i]), z = __builtin_clz(a[i+1]);
        if(x == y && y == z){
            cout << 1 << endl;
            return 0;
        }
    }
    int ans = 1e9;
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            for(int k = j+1; k <= N; k++){
                if((pfx[j] ^ pfx[i-1]) > (pfx[k] ^ pfx[j])){
                    ans = min(ans, k - j - 1 + j - i);
                }
            }
        }
    }
    cout << (ans < 1e9 ? ans : -1) << endl;
}
