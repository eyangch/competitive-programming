#include <bits/stdc++.h>

using namespace std;

int N, Q;
int pfx[200001];

int32_t main(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        int x; cin >> x;
        pfx[i] = pfx[i-1] ^ x;
    }
    for(int i = 0; i < Q; i++){
        int a, b; cin >> a >> b;
        cout << (pfx[a-1] ^ pfx[b]) << endl;
    }
}
