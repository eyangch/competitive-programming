#include <bits/stdc++.h>

using namespace std;

int Q;
long long K;

int getNthDigit(long long x, int d, int nlen){
    while(--nlen != d){
        x /= 10;
    }
    return x % 10;
}

long long getN(){
    char x;
    long long ret = 0;
    while((x = getchar_unlocked()) < '0'){}
    while(x >= '0'){
        ret *= 10;
        ret += x-'0';
        x = getchar_unlocked();
    }
    return ret;
}

int32_t main(){
    Q = getN();
    while(Q--){
        K = getN();
        int e10 = 0;
        long long pw = 1, cK = K;
        long long pw2 = 1;
        while(pw <= K){
            cK = K - pw;
            pw += 9LL * pw2 * ++e10;
            pw2 *= 10LL;
        }
        pw2 /= 10;
        putchar_unlocked(getNthDigit(pw2+cK/e10, cK%e10, e10)+'0');
        putchar_unlocked('\n');     
    }
}
