#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N, M, A;
    cin >> N >> M >> A;
    cout << (N/A + (N%A != 0)) * (M/A + (M%A != 0)) << endl;
    return 0;
}
