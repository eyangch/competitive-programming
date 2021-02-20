#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, a[200000];

int dc(int x, vector<int> v){
    if((int)v.size() <= 1) return 0;
    vector<int> v0, v1;
    for(int i : v){
        if(i & x){
            v1.push_back(i);
        }else{
            v0.push_back(i);
        }
    }
    int x0 = max(0, (int)v0.size() - 1) + dc(x / 2, v1);
    int x1 = max(0, (int)v1.size() - 1) + dc(x / 2, v0);
    return min(x0, x1);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    vector<int> v;
    for(int i = 0; i < N; i++) v.push_back(a[i]);
    cout << dc(1<<30, v) << endl;
}
