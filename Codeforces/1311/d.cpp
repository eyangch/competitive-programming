#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int T, A, B, C;
int cost[20001], cid[20001], ans, aid, bid;

void testA(int x){
    if(x > 20000 || x <= 0 || abs(A-x) > ans) return;
    for(int i = x; i <= 20000; i += x){
        int ccost = abs(A-x) + cost[i];
        if(ccost < ans){
            aid = x, bid = i;
            ans = ccost;
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        ans = 1e9;
        cin >> A >> B >> C;
        for(int i = 1; i <= 20000; i++){
            int x = C/i * i, y = (C/i+1) * i;
            cost[i] = abs(B-i) + min(abs(C-x), abs(C-y));
            if(abs(C-x) < abs(C-y)){
                cid[i] = x;
            }else{
                cid[i] = y;
            }
        }
        for(int i = 0; i <= 20000; i++){
            testA(A+i), testA(A-i);
        }
        cout << ans << endl << aid << " " << bid << " " << cid[bid] << endl;

    }
}
