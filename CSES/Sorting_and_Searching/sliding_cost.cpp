#include <bits/stdc++.h>

using namespace std;

int N, K;
int x[200000];
long long suml = 0, sumr = 0;
multiset<int> l, r;

void adj(){
    if(l.size() > r.size()+1){
        int mv = *l.rbegin();
        l.erase(l.find(*l.rbegin()));
        suml -= mv;
        r.insert(mv);
        sumr += mv;
    }
    if(r.size() > l.size()){
        int mv = *r.begin();
        r.erase(r.begin());
        sumr -= mv;
        l.insert(mv);
        suml += mv;
    }
}

void add(int num){
    if(num > *l.rbegin()){
        r.insert(num);
        sumr += num;
    }else{
        l.insert(num);
        suml += num;
    }
    adj();
}

void rm(int num){
    if(num > *l.rbegin()){
        r.erase(r.find(num));
        sumr -= num;
    }else{
        l.erase(l.find(num));
        suml -= num;
    }
    adj();
}

signed main(){
    scanf("%d%d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &x[i]);
    }
    l.insert(x[0]);
    suml += x[0];
    for(int i = 1; i < K-1; i++){
        add(x[i]);
    }
    for(int i = K-1; i < N; i++){
        if(i > 0) add(x[i]);
        if(i >= K){
            rm(x[i-K]);
        }
        long long median = *l.rbegin();
        long long lv = median * l.size() - suml;
        long long lr = sumr - median * r.size();
        printf("%lld ", lv+lr);
    }
    printf("\n");
}
