#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct op{
    int a, b, c;
};

int N, a[200000];

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N;
    int rxor = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        rxor ^= a[i];
    }
    if(N % 2 || !rxor){
        cout << "YES" << endl;
        vector<op> ans;
        for(int i = 0; i + 2 < N; i += 2){
            ans.push_back({i+1, i+2, i+3});
        }
        for(int i = 0; i + 2 < N; i += 2){
            ans.push_back({i+1, i+2, N});
        }
        cout << ans.size() << endl;
        for(op i : ans){
            cout << i.a << " " << i.b << " " << i.c << endl;
        }
    }else{
        cout << "NO" << endl;
    }
}
