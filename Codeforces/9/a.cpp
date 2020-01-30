#include <bits/stdc++.h>

using namespace std;

pair<int, int> frac(int a, int b){
    if(a == 0) return make_pair(0, 1);
    if(a == b) return make_pair(1, 1);
    for(int i = a; i > 0; i--){
        if(a % i == 0 && b % i == 0){
            a /= i;
            b /= i;
            break;
        }
    }
    return make_pair(a, b);
}

int main(){
    int y, w;
    cin >> y >> w;
    int x = max(y, w);
    cout << frac(7 - x, 6).first << "/" << frac(7 - x, 6).second << endl;
    return 0;
}
