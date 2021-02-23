#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int a, b, k;
bool s[200000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> k;
    string x1 = string(b, '1') + string(a, '0');
    if(!k){
        cout << "YES" << endl << x1 << endl << x1 << endl;
        return 0;
    }
    if(a+b-2 < k || b == 1 || a == 0){
        cout << "nO" << endl;
        return 0;
    }
    s[0] = 1;
    s[a+b-1] = 1;
    for(int i = 1; i <= b - 2; i++){
        s[b-i] = 1;
    } 
    int pt = 0;
    for(int i = a+b-2; i > k; i--){
        while(!pt || s[pt-1] || !s[pt]){
            pt++;
            if(pt == a+b){
                cout << "no" << endl;
                return 0;
            }
        }
        swap(s[pt], s[pt-1]);
        pt--;
    }
    cout << "YES" << endl << x1 << endl;
    for(int i = 0; i < a+b; i++){
        cout << s[i];
    }
    cout << endl;
}
