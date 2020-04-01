#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
    int total = 0;
    if(e > f){
        int sales = min(a, d);
        total += sales * e;
        d -= sales;
        total += f * min(b, min(c, d));
    }else{
        int sales = min(b, min(c, d));
        total += sales * f;
        d -= sales;
        total += e * min(a, d);
    }
    cout << total << endl;
    return 0;
}
