#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool isCoprime(ll a, ll b){
    if(a == 1) return true;
    if(b % a == 0) return false;
    int asqrt = sqrt(a);
    for(int i = 2; i < asqrt + 1; i++){
        if(a % i == 0 && b % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    ll N, nsqrt;
    cin >> N;
    nsqrt = sqrt(N);
    for(int i = nsqrt; i > 0; i--){
        if(N % i == 0 && isCoprime(i, N/i)){
            cout << i << " " << N/i << endl;
            break;
        }
    }
    return 0;
}
