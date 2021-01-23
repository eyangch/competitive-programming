#include <bits/stdc++.h>

using namespace std;

int N, M, C;
int a[1000000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    multiset<int> cur;
    for(int i = 0; i < M; i++){
        cur.insert(a[i]);
    }
    bool op = false;
    for(int i = M; i <= N; i++){
        if(*cur.rbegin() - *cur.begin() <= C){
            op = true;
            cout << i-M+1 << "\n";
        }
        if(i == N) break;
        cur.erase(cur.find(a[i-M]));
        cur.insert(a[i]);
    }
    if(!op) cout << "NONE" << endl;
}
