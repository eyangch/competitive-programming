#include <bits/stdc++.h>

using namespace std;

int N, Q;
int st[20][200000];
int l2[200001];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    fill(st[0], st[19]+200000, 1e9);
    for(int i = 0; i < N; i++){
        cin >> st[0][i];
    }
    for(int i = 1; i < 20; i++){
        for(int j = 0; j + (1<<i) - 1 < N; j++){
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    l2[1] = 0;
    for(int i = 2; i <= N; i++){
        l2[i] = l2[i/2]+1;
    }
    for(int i = 0; i < Q; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        int p2 = l2[b-a+1];
        cout << min(st[p2][a], st[p2][b-(1<<p2)+1]) << endl;
    }
}
