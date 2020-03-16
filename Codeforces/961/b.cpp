#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K, a[100000];
    bool t[100000];
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> t[i];
    }
    int c = 0;
    for(int i = 0; i < K; i++){
        if(!t[i]){
            c += a[i];
        }
    }
    int cmax = c;
    for(int i = 1; i < N - K + 1; i++){
        if(!t[i-1]){
            c -= a[i-1];
        }
        if(!t[i + K - 1]){
            c += a[i + K - 1];
        }
        cmax = max(cmax, c);
    }
    for(int i = 0; i < N; i++){
        if(t[i]) cmax += a[i];
    }
    cout << cmax << endl;
    return 0;
}
