#include <bits/stdc++.h>

using namespace std;

int N, K;
int x[200000];
map<int, int> v;

int32_t main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    int s = 0;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        v[x[i]]++;
        while((int)v.size() > K){
            if(--v[x[s]] == 0){
                v.erase(x[s]);
            }
            s++;
        }
        ans += i-s+1;
    }
    cout << ans << endl;
}
