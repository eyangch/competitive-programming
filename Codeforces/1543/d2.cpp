#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K;

int kxor(int a, int b){
    int mpK = 1;
    while(mpK <= a || mpK <= b) mpK *= K;
    int ret = 0;
    for(int i = mpK; i > 0; i /= K){
        int ax = a/i, bx = b/i;
        a %= i, b %= i;
        int sum = (ax + bx) % K;
        ret += sum * i;
    }
    return ret;
}

int kinvxor(int a, int b){
    int mpK = 1;
    while(mpK <= a || mpK <= b) mpK *= K;
    int ret = 0;
    for(int i = mpK; i > 0; i /= K){
        int ax = a/i, bx = b/i;
        a %= i, b %= i;
        int sum = (ax - bx + K) % K;
        ret += sum * i;
    }
    return ret;
}

int qry(int y){
    moo << y << endl;
    moo.flush();
    int ret; eat >> ret;
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        int cur = 0, prev = 0;
        for(int i = 0; i < N; i++){
            cur = (i % 2 ? kinvxor(prev, i) : kxor(prev, i));
            if(qry(cur)) break;
            prev = kinvxor(cur, prev);
        }
    }
}
