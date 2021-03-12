#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, M;
vector<int> apos, aneg, bpos, bneg;

int solve(vector<int> &a, vector<int> &b){
    vector<int> sat;
    for(int i : a){
        if(binary_search(b.begin(), b.end(), i)){
            sat.push_back(i);
        }
    }
    int ans = sat.size();
    int pushed = 0;
    for(int i : b){
        while(pushed < (int)a.size() && a[pushed] - pushed <= i){
            pushed++;
        }
        int r = i + pushed - 1;
        int inc = upper_bound(b.begin(), b.end(), r) - lower_bound(b.begin(), b.end(), i);
        inc += sat.end() - upper_bound(sat.begin(), sat.end(), r);
        ans = max(ans, inc);
    }
    return ans;
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        apos.clear(), aneg.clear();
        bpos.clear(), bneg.clear();
        eat >> N >> M;
        for(int i = 0; i < N; i++){
            int x; eat >> x;
            if(x > 0) apos.push_back(x);
            else aneg.push_back(-x);
        }
        for(int i = 0; i < M; i++){
            int x; eat >> x;
            if(x > 0) bpos.push_back(x);
            else bneg.push_back(-x);
        }
        sort(apos.begin(), apos.end());
        sort(aneg.begin(), aneg.end());
        sort(bpos.begin(), bpos.end());
        sort(bneg.begin(), bneg.end());
        int pos = solve(apos, bpos);
        int neg = solve(aneg, bneg);
        moo << pos + neg << endl;
    }
}
