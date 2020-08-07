#include <bits/stdc++.h>

using namespace std;

int get(int x, int (&BIT)[100000]){
    int sum = 0;
    for(; x > 0; x -= x&-x){
        sum += BIT[x];
    }
    return sum;
}

void upd(int x, int dv, int N, int (&BIT)[100000]){
    for(; x <= N; x += x&-x){
        BIT[x] += dv;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    return 0;
}


