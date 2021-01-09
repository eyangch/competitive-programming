#include <bits/stdc++.h>

using namespace std;

int N;
bool vis[1<<17];

void print(int x){
    int dv = 1<<(N-1);
    while(dv > 0){
        int v = x/dv;
        x %= dv;
        dv /= 2;
        putchar_unlocked(v + '0');
    }
    putchar_unlocked('\n');
}

int32_t main(){
    char a, b;
    a = getchar_unlocked();
    b = getchar_unlocked();
    if(b == '\n'){
        N = a-'0';
    }else{
        N = 10*(a-'0')+b-'0';
    }
    int x = 0;
    for(int i = 0; i < (1<<N); i++){
        print(x); 
        vis[x] = true;
        for(int j = 0; j < N; j++){
            if(vis[x ^ (1<<j)]) continue;
            x ^= (1<<j);
            break;
        }
    }
}
