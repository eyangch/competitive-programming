#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    moo << ceil(log2(N)) + 1 << endl;
}
