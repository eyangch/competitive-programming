#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        int N, M, K;
        string a, b;
        eat >> N >> M >> K >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ptr1 = 0, ptr2 = 0, u = 0, c = 0;
        while(true){
            if(ptr1 == N || ptr2 == M) break;
            int g = 0;
            if(a[ptr1] < b[ptr2]) g = 0;
            if(a[ptr1] > b[ptr2]) g = 1;
            if(g == c && u == K){
                g = !c;
            }
            if(g != c) u = 0;
            if(g) moo << b[ptr2];
            else moo << a[ptr1];
            if(g) ptr2++;
            else ptr1++;
            //moo << c << ' ' << g << ' ' << u << endl;
            c = g;
            u++;
        }
        moo << endl;
    }
}
