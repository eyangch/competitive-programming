#include <stdio.h>

int N;

void toh(int cN, int r1, int r2, int r3){
    if(cN == 0) return;
    toh(cN-1, r1, r3, r2);
    putchar_unlocked(r1 + '0');
    putchar_unlocked(' ');
    putchar_unlocked(r2 + '0');
    putchar_unlocked('\n');
    toh(cN-1, r3, r2, r1);
}

int main(){
    char a = getchar_unlocked();
    char b = getchar_unlocked();
    if(b == '\n'){
        N = a-'0';
    }else{
        N = 10*(a-'0')+b-'0';
    }
    int x = (1<<N) -1;
    int dv = 10000;
    while(true){
        if(x/dv > 0) break;
        dv /= 10;
    }
    while(x > 0){
        int v = x/dv;
        x %= dv;
        dv /= 10;
        putchar_unlocked(v + '0');
    }
    putchar_unlocked('\n');
    toh(N, 1, 3, 2);
}
