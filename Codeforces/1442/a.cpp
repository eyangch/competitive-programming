#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int a[30000];

signed main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        int mn = a[N-1];
        bool good = true;
        for(int i = N-2; i > 0; i--){
            mn = min(mn, a[i]);
            if(a[i] - a[i-1] > mn){
                good = false;
                break;
            }
            mn = min(mn, mn - (a[i] - a[i-1]));
        }
        cout << (good ? "YES" : "NO") << endl;
    }
}
