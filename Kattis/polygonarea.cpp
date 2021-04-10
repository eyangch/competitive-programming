#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define f first
#define s second

using namespace std;
typedef pair<int, int> pii;

int N;
pii p[1000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    while(true){
        eat >> N;
        if(N == 0) break;
        double a = 0;
        for(int i = 0; i < N; i++){
            eat >> p[i].f >> p[i].s;
        }
        for(int i = 0; i < N-1; i++){
            a += p[i].f * p[i+1].s;
        }
        a += p[N-1].f * p[0].s;
        for(int i = 1; i < N; i++){
            a -= p[i].f * p[i-1].s;
        }
        a -= p[0].f * p[N-1].s;
        a /= 2;
        moo << fixed << setprecision(1);
        if(a > 0){
            moo << "CCW " << round(a * 10) / 10 << endl;
        }else{
            moo << "CW " << round(-a * 10) / 10 << endl;
        }
    }
}
