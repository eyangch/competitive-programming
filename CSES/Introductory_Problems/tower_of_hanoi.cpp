#include <bits/stdc++.h>

using namespace std;

int N;

void toh(int cN, int r1, int r2, int r3){
    if(cN == 0) return;
    toh(cN-1, r1, r3, r2);
    cout << r1 << " " << r2 << endl;
    toh(cN-1, r3, r2, r1);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << (1<<N) - 1 << endl;
    toh(N, 1, 3, 2);
}
