#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, a[2][200000], b[2][200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    int cnt = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            eat >> a[i][j];
            cnt += a[i][j];
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            eat >> b[i][j];
            cnt -= b[i][j];
        }
    }
    if(cnt != 0){
        moo << -1 << endl;
        return 0;
    }
    int pf0 = 0, pf1 = 0, ret = 0;
    for(int i = 0; i < N; i++){
        pf0 += a[0][i] - b[0][i];
        pf1 += a[1][i] - b[1][i];
        ret += abs(pf0) + abs(pf1);
        if(pf0 * pf1 >= 0){}
        else if(pf0 < pf1 && (a[1][i] || b[0][i])){
            pf0++;
            pf1--;
            ret--;
        }else if(pf0 > pf1 && (a[0][i] || b[1][i])){
            pf1++;
            pf0--;
            ret--;
        }
    }
    moo << ret << endl;
}