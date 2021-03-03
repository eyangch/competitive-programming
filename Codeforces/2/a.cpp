#include <bits/stdc++.h>
#define burp "\n"
#define moo cout
#define eat cin
#define f first
#define s second

using namespace std;

int N, dv[1000];
set<string> w;
string a[1000];
map<string, int> tscore;

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i] >> dv[i];
    }
    for(int i = 0; i < N; i++){
        tscore[a[i]] += dv[i];
    }
    int mx = -1e7;
    for(pair<string, int> i : tscore){
        if(i.s >= mx){
            if(i.s > mx) w.clear();
            w.insert(i.f);
            mx = i.s;
        }
    }
    tscore.clear();
    for(int i = 0; i < N; i++){
        if(w.count(a[i])){
            if((tscore[a[i]] += dv[i]) >= mx){
                moo << a[i] << burp;
                return 0;
            }
        }
    }
}
