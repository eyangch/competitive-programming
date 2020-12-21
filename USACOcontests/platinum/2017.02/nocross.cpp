#include <bits/stdc++.h>

using namespace std;

int N;
int rloc[100001];
int BIT[200001];

void upd(int i, int x){
    for(; i <= N; i += i&-i){
        BIT[i] = max(BIT[i], x);
    }
}

int qry(int i){
    int ret = 0;
    for(; i > 0; i -= i&-i){
        ret = max(ret, BIT[i]);
    }
    return ret;
}

signed main(){
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        rloc[x] = i;
    }
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        vector<int> ploc, pamt;
        for(int j = x-4; j <= x+4; j++){
            if(j <= 0 || rloc[j] == i || j > N){
                continue;
            }
            ploc.push_back(rloc[j]);
            pamt.push_back(qry(rloc[j])+1);
        }
        for(int j = 0; j < (int)ploc.size(); j++){
            upd(ploc[j]+1, pamt[j]);
        }
    }
    cout << qry(N) << endl;
}
