#include <bits/stdc++.h>

using namespace std;

int qry(int x){
    int sum = 0;
    for(; x > 0; x -= x&-x) sum += BIT[x];
    return sum;
}

void upd(int x, int dv){
    for(; x <= N; x += x&-x) BIT[x] += dv;
}
