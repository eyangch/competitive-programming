#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, a[100000], S, F, diff;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    cin >> S >> F;
    diff = F - S;
    int total = 0;
    for(int i = 1; i < diff + 1; i++){
        total += a[i];
    }
    int tmax = total, tidx = -(1 + 1) + S;
    if(tidx <= 0){
        tidx += N;
    }
    for(int i = 0; i < N; i++){
        total -= a[i];
        total += a[(i + diff) % N];
        int tmp = -(i + 1) + S;
        if(tmp <= 0){
            tmp += N;
        }
        if(total > tmax){
            tmax = total;
            tidx = tmp;
        }else if(total == tmax){
            tidx = min(tidx, tmp);
        }
    }
    cout << tidx << endl;
    return 0;
}
