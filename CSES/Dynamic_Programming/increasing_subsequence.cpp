#include <bits/stdc++.h>

using namespace std;

int N;
int x[200000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    vector<int> lis;
    for(int i = 0; i < N; i++){
        int idx = lower_bound(lis.begin(), lis.end(), x[i]) - lis.begin();
        if(idx == (int)lis.size()) lis.push_back(0);
        lis[idx] = x[i];
    }
    cout << lis.size() << endl;
}
