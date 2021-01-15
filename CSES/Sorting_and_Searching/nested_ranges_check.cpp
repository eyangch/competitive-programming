#include <bits/stdc++.h>

using namespace std;

struct r{
    int x;
    int y;
    int i;
};

int N;
r a[200000];
int ans[200000];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i].x >> a[i].y;
        a[i].i = i;
    }
    sort(a, a+N, [](r a, r b){
        if(a.y == b.y) return a.x > b.x;
        return a.y < b.y;
    });
    set<int> pv;
    for(int i = 0; i < N; i++){
        if(pv.lower_bound(a[i].x) == pv.end()){
            ans[a[i].i] = 0;
        }else{
            ans[a[i].i] = 1;
        }
        pv.insert(a[i].x);
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    sort(a, a+N, [](r a, r b){
        if(a.x == b.x) return a.y > b.y;
        return a.x < b.x;
    });
    pv.clear();
    for(int i = 0; i < N; i++){
        if(pv.lower_bound(a[i].y) == pv.end()){
            ans[a[i].i] = 0;
        }else{
            ans[a[i].i] = 1;
        }
        pv.insert(a[i].y);
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
