#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, a[100000];
vector<int> occ[100001];
int x[2];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a[i]--;
        occ[a[i]].push_back(i);
    }
    int ans = 0;
    x[0] = x[1] = N;
    for(int i = 0; i < N; i++){
        if(x[0] != a[i] && x[1] != a[i]){
            auto it1 = upper_bound(occ[x[0]].begin(), occ[x[0]].end(), i);
            auto it2 = upper_bound(occ[x[1]].begin(), occ[x[1]].end(), i);
            int rp = 0;
            if(it1 == occ[x[0]].end()){
                rp = 1;
            }else if(it2 == occ[x[1]].end()){
                rp = 0;
            }else if(*it1 < *it2){
                rp = 0;
            }else{
                rp = 1;
            }
            x[rp] = a[i];
            ans++;
        }else if(x[0] != a[i]){
            x[0] = a[i];
            ans++;
        }else if(x[1] != a[i]){
            x[1] = a[i];
            ans++;
        }
    }
    cout << ans << endl;
}
