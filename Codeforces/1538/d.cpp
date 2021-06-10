#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int sieve[100000];
int T, a, b, k;
vector<int> p;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    for(int i = 2; i < 100000; i++){
        if(!sieve[i]){
            p.push_back(i);
            for(int j = i; j < 100000; j += i){
                sieve[j] = i;
            }
        }
    }
    eat >> T;
    while(T--){
        eat >> a >> b >> k;
        if(a < b) swap(a, b);
        if(k == 1){
            if(a % b == 0 && a != b){
                moo << "YEs" << endl;
            }else{
                moo << "no" << endl;
            }
            continue;
        }
        int pfa = 0, pfb = 0;
        for(int i : p){
            if(i * i > a){
                break;
            }
            while(a % i == 0){
                pfa++;
                a /= i;
            }
        }
        if(a > 1) pfa++;
        for(int i : p){
            if(i * i > b) break;
            while(b % i == 0){
                pfb++;
                b /= i;
            }
        }
        if(b > 1) pfb++;
        if(pfa + pfb >= k){
            moo << "yeS" << endl;
        }else{
            moo << "nO" << endl;
        }
    }
}
