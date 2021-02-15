#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define int long long

using namespace std;
typedef pair<int, int> pii;

int MOD = 1e9+7;
int N, pfx[100001], sfx[100001];
pii a[100000];

int add(int a, int b){
    return (a + b) % MOD;
}

int sub(int a, int b){
    return ((a - b) % MOD + MOD) % MOD;
}

int mul(int a, int b){
    return (a * b) % MOD;
}

int bpow(int a, int b){
    int ret = 1;
    for(int i = 0; i < 63; i++){
        if(b & (1LL<<i)){
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
    }
    return ret;
}

int divm(int a, int b){
    return a * bpow(b, MOD-2) % MOD;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i].fi >> a[i].se;
    }
    int num = 1;
    for(int i = 0; i < N; i++){
        num = mul(num, a[i].se+1);
    }
    cout << num << " ";
    MOD = 1e9+6;
    pfx[0] = 1;
    for(int i = 0; i < N; i++){
        pfx[i+1] = mul(pfx[i], a[i].se+1);
    }
    sfx[N] = 1;
    for(int i = N-1; i >= 0; i--){
        sfx[i] = mul(sfx[i+1], a[i].se+1);
    }
    MOD=1e9+7;
    int sum = 1;
    for(int i = 0; i < N; i++){
        sum = mul(sum, divm(sub(bpow(a[i].fi, a[i].se+1), 1), sub(a[i].fi, 1)));
    }
    cout << sum << " ";
    int prod = 1;
    for(int i = 0; i < N; i++){
        int x = bpow(a[i].fi, a[i].se * (a[i].se + 1) / 2LL);
        MOD = 1e9+6;
        int exp = mul(pfx[i], sfx[i+1]);
        MOD = 1e9+7;
        prod = mul(prod, bpow(x, exp));
    }
    cout << prod << endl;
}
