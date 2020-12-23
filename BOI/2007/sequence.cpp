#include <bits/stdc++.h>

using namespace std;

int N;
long long a[1000000];
int l2[1000001];
int st[20][1000000];
long long ans = 0;

int idmaxf(int x, int y){
    if(a[x] >= a[y]){
        return x;
    }else{
        return y;
    }
}

int query(int l, int r){
    int p2 = l2[r-l+1];
    return idmaxf(st[p2][l], st[p2][r-(1<<p2)+1]);
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    l2[1] = 0;
    for(int i = 2; i <= N; i++){
        l2[i] = l2[i/2]+1;
    }
    iota(st[0], st[0]+N, 0);
    for(int i = 1; i <= l2[N]; i++){
        for(int j = 0; j + (1<<i) - 1 < N; j++){
            st[i][j] = idmaxf(st[i-1][j], st[i-1][j + (1<<(i-1))]);
        }
    }
    queue<pair<int, int>> q;
    q.push({0, N-1});
    while(!q.empty()){
        int l = q.front().first, r = q.front().second;
        q.pop();
        if(l == r){
            continue;
        }
        int maxid = query(l, r);
        if(maxid > l){
            ans += a[maxid];
            q.push({l, maxid-1});
        }
        if(maxid < r){
            ans += a[maxid];
            q.push({maxid+1, r});
        }
    }
    cout << ans << endl;
}
