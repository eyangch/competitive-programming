#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 998244353;
int N, M, a[200000], b[200000];
vector<int> mn;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N >> M;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    for(int i = 0; i < M; i++){
        eat >> b[i];
    }
    mn.push_back(N-1);
    for(int i = N-2; i >= 0; i--){
        if(a[mn.back()] > a[i]) mn.push_back(i);
    }
    reverse(mn.begin(), mn.end());
    if(a[mn[0]] != b[0]){
        moo << 0 << endl;
        return 0;
    }
    int ans = 1, ptr = 0;
    for(int i = 1; i < M; i++){
        while(a[mn[ptr]] < b[i]){
            ptr++;
            if(ptr >= (int)mn.size()){
                moo << 0 << endl;
                return 0;
            }
        }
        if(a[mn[ptr]] > b[i]){
            moo << 0 << endl;
            return 0;
        }
        ans = ans * (mn[ptr] - mn[ptr-1]) % MOD;
    }
    moo << ans << endl;
}
