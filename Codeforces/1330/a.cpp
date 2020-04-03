#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    //freopen("cin", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int a[n];
        bool place[301];
        fill(place, place + 301, false);
        int lg = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            place[a[i]] = true;
        }
        int i;
        for(i = 1; i < 301; i++){
            if(!place[i]) x--;
            if(x < 0){
                break;
            }
        }
        cout << i-1 << endl;
    }
    return 0;
}
