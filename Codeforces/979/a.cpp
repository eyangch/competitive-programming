#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

ll N;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << (N ? (N % 2 ? N/2+1 : N+1) : 0) << endl;
}
