#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("cin", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        set<int> already;
        int mnum = 0;
        bool isperm[n], ispermbk[n];
        fill(isperm, isperm + n, false);
        fill(ispermbk, ispermbk + n, false);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n-1; i++){
            if(already.find(a[i]) != already.end()){
                break;
            }
            mnum = max(mnum, a[i]);
            already.insert(a[i]);
            if(mnum == already.size()){
                isperm[i] = true;
            }
        }
        set<int> already2;
        int mnum2 = 0;
        for(int i = n-1; i >= 1; i--){
            if(already2.find(a[i]) != already2.end()){
                break;
            }
            mnum2 = max(mnum2, a[i]);
            already2.insert(a[i]);
            //cout << mnum2 << already2.size() << endl;
            if(mnum2 == already2.size()){
                ispermbk[i] = true;
            }
        }
        vector<pair<int, int>> valid;
        for(int i = 0; i < n-1; i++){
            //cout << i << " " << isperm[i] << " " << ispermbk[i] << endl;
            if(isperm[i] && ispermbk[i+1]){
                valid.push_back(pair<int, int>(i+1, n-i-1));
            }
        }
        cout << valid.size() << endl;
        for(int i = 0; i < valid.size(); i++){
            cout << valid[i].first << " " << valid[i].second << endl;
        }
    }
    return 0;
}
