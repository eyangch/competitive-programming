#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, M, fw[200000], bk[200000];
string s, t;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> s >> t;
    for(int i = 0, ptr = 0; i < M; i++){
        while(s[ptr] != t[i]) ptr++;
        fw[i] = ptr++;
    }
    for(int i = M-1, ptr = N-1; i >= 0; i--){
        while(s[ptr] != t[i]) ptr--;
        bk[i] = ptr--;
    }
    int ans = 0;
    for(int i = 0; i < M-1; i++){
        ans = max(bk[i+1] - fw[i], ans);
    }
    cout << ans << endl;
}
