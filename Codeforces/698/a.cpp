#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, restdays = 0, a[100];
    int prev = 0; // -1 = gym 1 = contest
    cin >> N;
    if(N < 2){
        int x;
        cin >> x;
        if(x == 0) cout << N << endl;
        else cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N-1; i++){
        if(a[i] == 0){
            restdays++;
            prev = 0;
        }else if(a[i] == 3){
            if(prev == 1){
                prev = 2;
            }else if(prev == 2){
                prev = 1;
            }
        }else{
            if(prev == a[i]){
                restdays++;
                prev = 0;
            }else{
                prev = a[i];
            }
        }
    }
    if(a[N-1] == 0){
        restdays++;
    }else if(a[N-1] == prev){
        restdays++;
    }
    cout << restdays << endl;
    return 0;
}
