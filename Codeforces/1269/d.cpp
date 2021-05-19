#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, a[300000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    int x = 0, y = 0;
    for(int i = 0; i < N; i++){
        int a1 = a[i]/2, a2 = a[i]/2+a[i]%2;
        if(i%2) swap(a1, a2);
        x += a1, y += a2;
    }
    moo << min(x, y) << endl;
}
