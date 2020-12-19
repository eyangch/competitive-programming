#include <bits/stdc++.h>
#define int long long

using namespace std;

int T, K;

signed main(){
    cin >> T;
    while(T--){
        cin >> K;
        if(K % 2 == 1){
            cout << -1 << endl;
        }else{
            vector<bool> ans;
            int bf = 62;
            while(K > 0){
                if(K - (1LL << bf) < 0){
                    bf = 1;
                    ans.push_back(1);
                }else{
                    ans.push_back(0);
                }
                K -= 1LL << bf;
                bf++;
            }
            cout << ans.size() << endl;
            for(bool i : ans){
                cout << i << " ";
            }
            cout << endl;
        }
    }
}
