#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, d[2000];
vector<pair<int, int>> e;
vector<int> v[2];

void qry(int r){
    moo << "? " << r+1 << endl;
    moo.flush();
    for(int i = 0; i < N; i++){
        eat >> d[i];
        if(d[i] == 1) e.push_back({r+1, i+1});
    }
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    qry(0);
    for(int i = 1; i < N; i++){
        v[d[i] % 2].push_back(i);
    }
    if(v[0].size() > v[1].size()){
        v[0].swap(v[1]);
        e.clear();
    }
    for(int i : v[0]) qry(i);
    moo << '!' << endl;
    moo.flush();
    for(pair<int, int> i : e) moo << i.first << " " << i.second << endl;
}
