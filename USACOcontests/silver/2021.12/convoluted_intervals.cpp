#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long
#define fi first
#define se second

using namespace std;

int N, M;
int A[5001], B[5001], s[10001];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        int a, b; eat >> a >> b;
        A[a]++, B[b]++;
    }
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= M; j++){
            s[i+j] += A[i] * A[j];
            s[i+j+1] -= B[i] * B[j];
        }
    }
    int ans = 0;
    for(int i = 0; i <= 2*M; i++){
        ans += s[i];
        moo << ans << endl;
    }
}
