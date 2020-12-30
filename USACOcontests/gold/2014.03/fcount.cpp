#include <bits/stdc++.h>

using namespace std;

int N;
int a[500];

bool works(int rm){
    vector<int> deg;
    for(int i = 0; i < N+1; i++){
        if(i != rm) deg.push_back(a[i]);
    }
    vector<int> cnt[N];
    for(int i = 0; i < N; i++){
        cnt[deg[i]].push_back(i);
    }
    for(int i = 0; i < N-1; i++){
        int q = deg[i];
        deg[i] = 0;
        int cqid = 0;
        for(; cnt[q][cqid] != i; cqid++){}
        cnt[q].erase(cnt[q].begin()+cqid); cnt[0].push_back(i);
        int nxt = cnt[N-1-i].size();
        for(int j = N-1-i; j > 0 && q > 0; j--){
            int nnxt = cnt[j-1].size();
            while(nxt > 0 && q > 0){
                int x = cnt[j].back();
                deg[x]--;
                cnt[j-1].push_back(x);
                cnt[j].pop_back();
                nxt--; q--;
            }
            nxt = nnxt;
        }
        if(q > 0) return false;
    }
    return (cnt[0].size() == N);
}

int32_t main(){
    freopen("fcount.in", "r", stdin);
    freopen("fcount.out", "w", stdout);
    scanf("%d", &N);
    int sum = 0;
    for(int i = 0; i < N+1; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    vector<int> ans;
    for(int i = 0; i < N+1; i++){
        if(sum % 2 != a[i] % 2) continue;
        if(works(i)){
            ans.push_back(i+1);
        }
    }
    printf("%ld\n", ans.size());
    for(int i : ans){
        printf("%d\n", i);
    }
}
