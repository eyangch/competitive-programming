#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int testcase = 0; testcase < T; testcase++){
        int N, D, hb[100];
        cin >> N >> D;
        for(int i = 0; i < N; i++){
            cin >> hb[i];
        }
        for(int i = 1; i < N && D > 0; i++){
            hb[0] += min(D / i, hb[i]);
            D -= min(D, hb[i] * i);
        }
        cout << hb[0] << endl;
    }
    return 0;
}
