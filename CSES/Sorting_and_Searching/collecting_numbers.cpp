#include <bits/stdc++.h>

using namespace std;

int N;
int x[200000];

void print(int x){
    int dv = 1000000;
    while(true){
        if(x/dv > 0) break;
        dv /= 10;
    }
    while(dv > 0){
        int v = x/dv;
        x %= dv;
        dv /= 10;
        putchar_unlocked(v + '0');
    }
    putchar_unlocked('\n');
}

int getN(){
    char x;
    int ret = 0;
    while((x = getchar_unlocked()) < '0'){}
    while(x >= '0'){
        ret *= 10;
        ret += x-'0';
        x = getchar_unlocked();
    }
    return ret;
}

int32_t main(){
    N = getN();
    for(int i = 0; i < N; i++){
        int num = getN();
        x[num-1] = i;
    }
    int rounds = 1;
    for(int i = 1; i < N; i++){
        if(x[i] < x[i-1]) rounds++;
    }
    print(rounds);
}
