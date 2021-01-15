#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long x[200001];

int32_t main(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> x[i];
        x[i] += x[i-1];
    }
    for(int i = 0; i < Q; i++){
        int a, b; cin >> a >> b;
        cout << x[b] - x[a-1] << endl;
    }
}
