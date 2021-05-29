#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, sumh, suml;
set<int> ls, low, hi;

void bal(){
    while(hi.size() > ls.size()) suml += *hi.begin(), sumh -= *hi.begin(), low.insert(*hi.begin()), hi.erase(hi.begin());
    while(hi.size() < ls.size() && low.size()) sumh += *low.rbegin(), suml -= *low.rbegin(), hi.insert(*low.rbegin()), low.erase(*low.rbegin());
    while(hi.size() && low.size() && *hi.begin() < *low.rbegin()){
        int a = *hi.begin(), b = *low.rbegin();
        sumh -= a, sumh += b, suml -= b, suml += a;
        hi.erase(a), low.erase(b), hi.insert(b), low.insert(a);
    }
}

void add(int i){
    if(low.size() && i > *low.rbegin()) hi.insert(i), sumh += i;
    else low.insert(i), suml += i;
    bal();
}

void rm(int i){
    if(hi.size() && i >= *hi.begin()) hi.erase(i), sumh -= i;
    else low.erase(i), suml -= i;
    bal();
}

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        int tp, d; eat >> tp >> d;
        if(tp == 0){
            if(d > 0) add(d);
            else rm(-d);
        }else{
            if(d > 0){
                if(!ls.size()){
                    ls.insert(d);
                }else if(d < *ls.begin()){
                    int bf = *ls.begin();
                    ls.insert(d);
                    add(bf);
                }else{
                    ls.insert(d);
                    add(d);
                }
            }else{
                if(-d == *ls.begin()){
                    ls.erase(-d);
                    if(ls.size()) rm(*ls.begin());
                }else{
                    ls.erase(-d);
                    rm(-d);
                }
            }
        }
        bal();
        moo << sumh * 2 + suml + (ls.size() ? *ls.begin() : 0) << endl;
    }
}
