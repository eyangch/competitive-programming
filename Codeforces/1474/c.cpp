#include <bits/stdc++.h>

using namespace std;

int T;
int N;
int a[2000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N*2; i++){
            cin >> a[i];
        }
        sort(a, a+2*N);
        multiset<int> glw;
        for(int i = 0; i < 2*N; i++){
            glw.insert(a[i]);
        }
        bool fin = false;
        for(int r = 0; r < 2*N-1; r++){
            multiset<int> lw = glw;
            lw.erase(lw.find(a[2*N-1]));
            lw.erase(lw.find(a[r]));
            vector<pair<int, int>> ans;
            int bad = 0;
            int prev = a[2*N-1];
            for(int i = 2*N-2; (int)lw.size() > 0 && i >= 0; i--){
                auto fit = lw.find(a[i]);
                if(fit == lw.end()) continue;
                lw.erase(fit);
                auto it = lw.find(prev - a[i]);
                if(it == lw.end()){
                    bad++;
                    lw.insert(a[i]);
                    if(bad == 2) break;
                    continue;
                }
                ans.push_back({*it, a[i]});
                prev = a[i];
                lw.erase(it);
            }
            if((int)ans.size() == N-1){
                cout << "YES" << endl << a[r] + a[2*N-1] << endl << a[r] << " " << a[2*N-1] << endl;;
                for(int i = 0; i < N-1; i++){
                    cout << ans[i].first << " " << ans[i].second << endl;
                }
                fin = true;
                break;
            }
        }
        if(!fin){
            cout << "NO" << endl;
        }
    }
}
