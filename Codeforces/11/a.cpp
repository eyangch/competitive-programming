#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, D, b[2000], ret = 0;
    cin >> N >> D;
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    for(int i = 1; i < N; i++){
        int x = ((b[i] > b[i-1]) ? 0 : ((b[i-1] - b[i]) / D + 1));
        ret += x;
        b[i] += x * D;
    }
    cout << ret << endl;
    return 0;
}
