#include <bits/stdc++.h>
#define int long long

#define s second
using namespace std;

int N;
pair<int, int> c[2500];
int ans = 0;
vector<int> pfxl[2500], pfxr[2500];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c[i].first >> c[i].second;
    }
    sort(c, c+N);
    ans = 1 + N + (N*(N-1)/2);
    for(int i = 0; i < N-1; i++){
        pfxl[i+1] = pfxl[i];
        pfxl[i+1].push_back(c[i].s);
        sort(pfxl[i+1].begin(), pfxl[i+1].end());
    }
    for(int i = N-1; i > 0; i--){
        pfxr[i-1] = pfxr[i];
        pfxr[i-1].push_back(c[i].s);
        sort(pfxr[i-1].begin(), pfxr[i-1].end());
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int up = max(c[i].s, c[j].s);
            int dn = min(c[i].s, c[j].s);
            int l = upper_bound(pfxl[i].begin(), pfxl[i].end(), up) - upper_bound(pfxl[i].begin(), pfxl[i].end(), dn);
            int r = upper_bound(pfxr[j].begin(), pfxr[j].end(), up) - upper_bound(pfxr[j].begin(), pfxr[j].end(), dn);
            ans += l + r;
            ans += l * r;
        }
    }
    cout << ans << endl;
}
