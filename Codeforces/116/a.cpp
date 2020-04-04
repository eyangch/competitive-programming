#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int n; cin >> n;
    int mtotal = 0, total = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        total += b - a;
        mtotal = max(total, mtotal);
    }
    cout << mtotal << endl;
    return 0;
}

