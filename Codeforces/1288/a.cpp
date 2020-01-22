#include <bits/stdc++.h>
#define EPSILON 0.0000001

using namespace std;
typedef long long ll;
typedef double db;

db calc(int D, int x){
    return x + ((db)D / (x + 1));
}

int main(){
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        int N, D;
        cin >> N >> D;
        ll h = 1000000000;
        ll l = 0;
        ll m = (h + l) / 2;
        db prev = calc(D, m);
        while(h >= l){
            if(calc(D, m - 1) <= prev){
                h = m - 1;
            }else if (calc(D, m + 1) <= prev){
                l = m + 1;
            }else{
                break;
            }
            m = (h + l) / 2;
            prev = calc(D, m);
        }
        if(prev <= N) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
