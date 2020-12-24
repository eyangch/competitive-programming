#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[20000];
int n1[1000], n2[1000];

signed main(){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    for(int i = 0; 2*i+1 < N; i++){
        n1[a[i]]++;
        n2[a[i*2]]++;
        n2[a[i*2+1]]++;
        n2[a[i]]--;
        int q = 0;
        bool good = true;
        for(int j = 0; j < M; j++){
            if(j > 0) q += n1[j-1];
            q -= n2[j];
            if(q < 0){
                good = false;
                break;
            }
        }
        ans = max(ans, good*(i+1));
    }
    cout << ans << endl;
}
