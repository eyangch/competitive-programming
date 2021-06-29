#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, c[100000], t[100000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++) eat >> c[i];
    for(int i = 0; i < N; i++) eat >> t[i];
    if(c[0] != t[0] || c[N-1] != t[N-1]){
        moo << "No" << endl;
        return 0;
    }
    multiset<int> d1, d2;
    for(int i = 1; i < N; i++) d1.insert(c[i] - c[i-1]);
    for(int i = 1; i < N; i++) d2.insert(t[i] - t[i-1]);
    moo << (d1 == d2 ? "Yes" : "No") << endl;
}
