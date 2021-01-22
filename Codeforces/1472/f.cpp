#include <bits/stdc++.h>

using namespace std;

struct rt{
    bool a, b;
};

struct st{
    int a, b, c;
};

int T;
int N, M;
map<int, rt> b;
map<int, st> dp;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> M;
        b.clear(), dp.clear();
        for(int i = 0; i < M; i++){
            int r, c; cin >> r >> c;
            if(!b.count(c)) b[c] = {false, false};
            if(r == 1) b[c].a = true;
            if(r == 2) b[c].b = true;
        }
        dp[0] = {1, 0, 0};
        for(auto it = b.begin(); it != b.end(); it++){
            int loc = it->first;
            rt bloc = it->second;
            auto it2 = dp.rbegin();
            int ploc = it2->first;
            int m2 = (loc - ploc) % 2;
            st pdp = it2->second;
            st cdp = {0, 0, 0};
            if(bloc.a && bloc.b){
                cdp.a = pdp.a;
            }else if(bloc.a){
                if(m2){
                    cdp.a = pdp.c;
                }else{
                    cdp.a = pdp.b;
                }
                cdp.c = pdp.a;
            }else{
                if(!m2){
                    cdp.a = pdp.c;
                }else{
                    cdp.a = pdp.b;
                }
                cdp.b = pdp.a;
            }
            dp[loc] = cdp;
        }
        st last = dp.rbegin() -> second;
        if(last.a){
            cout << "yEs" << endl;
        }else{
            cout << "nO" << endl;
        }
    }
}
