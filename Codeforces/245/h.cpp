#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, Q;
string s;
int dp1[5000][5000], dp2[5000][5000];

bool dpf1(int a, int b){
    if(b < a) return true;
    if(~dp1[a][b]) return dp1[a][b];
    if(s[a] == s[b] && dpf1(a+1, b-1)){
        return (dp1[a][b] = true);
    }
    return false;
}

int dpf2(int a, int b){
    if(b < a) return 0;
    if(~dp2[a][b]) return dp2[a][b];
    return (dp2[a][b] = dpf1(a, b) + dpf2(a+1, b) + dpf2(a, b-1) - dpf2(a+1, b-1));
}

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> s >> Q;
    N = s.size();
    memset(&dp1[0][0], -1, sizeof(dp1));
    memset(&dp2[0][0], -1, sizeof(dp2));
    for(int i = 0; i < Q; i++){
        int l, r; cin >> l >> r;
        cout << dpf2(l-1, r-1) << endl;
    }
}
