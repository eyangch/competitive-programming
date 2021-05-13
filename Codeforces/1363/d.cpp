#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int T, N, K;
vector<int> sub[1000], q;

int qry(){
    if(q.empty()) return -1;
    moo << "? " << q.size();
    for(int i : q) moo << ' ' << i;
    q.clear();
    moo << endl;
    moo.flush();
    int ret; eat >> ret;
    return ret;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N >> K;
        for(int i = 0; i < K; i++){
            sub[i].clear();
            int c; eat >> c;
            for(int j = 0; j < c; j++){
                int x; eat >> x;
                sub[i].push_back(x);
            }
        }
        for(int i = 1; i <= N; i++) q.push_back(i);
        int mx = qry();
        int lo = 1, hi = N, mid = 0, ans = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            for(int i = 1; i < mid; i++){
                q.push_back(i);
            }
            int cur = qry();
            if(cur < mx){
                ans = mid, lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        vector<int> pwd;
        for(int i = 0; i < K; i++){
            bool ok = true;
            for(int j : sub[i]){
                if(j == ans) ok = false;
            }
            if(ok){
                pwd.push_back(mx);
            }else{
                bool rm[N];
                fill(rm, rm+N, true);
                for(int j : sub[i]){
                    rm[j-1] = false;
                }
                for(int j = 0; j < N; j++){
                    if(rm[j]) q.push_back(j+1);
                }
                pwd.push_back(qry());
            }
        }
        moo << '!';
        for(int i = 0; i < K; i++){
            moo << ' ' << pwd[i];
        }
        moo << endl;
        moo.flush();
        string s; eat >> s;
        if(s != "Correct") break;
    }
}
