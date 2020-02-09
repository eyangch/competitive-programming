#include <bits/stdc++.h>

using namespace std;

int calcTri(int a, int b, int c){
    return min(a + b - c, min(a + c - b, b + c - a));
}

int main(){
    int x[4], ret = 0;
    cin >> x[0] >> x[1] >> x[2] >> x[3];
    sort(x, x + 4);
    ret = max(calcTri(x[0], x[1], x[2]), calcTri(x[1], x[2], x[3]));
    if(ret < 0) cout << "IMPOSSIBLE" << endl;
    else if(ret == 0) cout << "SEGMENT" << endl;
    else cout << "TRIANGLE" << endl;
    return 0;
}
