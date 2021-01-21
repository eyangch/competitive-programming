#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int a[200000], pfx[200000], sfx[200000];

bool solve(int i){
    if(i > 0 && pfx[i-1] == -1) return false;
    if(i < N-2 && sfx[i+2] == -1) return false;
    int p = (i > 0 ? a[i-1] - pfx[i-1] : 0);
    int s = (i < N-2 ? a[i+2] - sfx[i+2] : 0);
    int x = a[i+1], y = a[i];
    if(p > x) return false;
    x -= p;
    if(x > y) return false;
    y -= x;
    if(y != s) return false;
    return true;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        fill(pfx, pfx+N, -1);
        fill(sfx, sfx+N, -1);
        pfx[0] = sfx[N-1] = 0;
        for(int i = 0; i < N-1; i++){
            if(a[i] - pfx[i] <= a[i+1]){
                pfx[i+1] = (a[i] - pfx[i]);
            }else{
                break;
            }
        }
        for(int i = N-1; i > 0; i--){
            if(a[i] - sfx[i] <= a[i-1]){
                sfx[i-1] = (a[i] - sfx[i]);
            }else{
                break;
            }
        }
        if(a[N-1] - pfx[N-1] == 0){
            cout << "YES" << endl;
            continue;
        }
        bool yes = false;
        for(int i = 0; i < N-1; i++){
            yes |= solve(i);
            if(yes) break;
        }
        if(yes){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
