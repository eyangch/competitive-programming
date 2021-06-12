#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, p[200000], c[200000];
bool vis[200000];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> N;
        for(int i = 0; i < N; i++) eat >> p[i];
        for(int i = 0; i < N; i++) eat >> c[i];
        fill(vis, vis+N, 0);
        int ans = 1e9;
        for(int i = 0; i < N; i++){
            vector<int> cy;
            int ptr = i;
            while(!vis[ptr]){
                vis[ptr] = true;
                cy.push_back(c[ptr]);
                ptr = p[ptr] - 1;
            }
            if(cy.empty()) continue;
            for(int j = 1; j * j <= (int)cy.size(); j++){
                if((int)cy.size() % j == 0){
                    for(int k = 0; k < j; k++){
                        int match = cy[k];
                        bool good = true;
                        for(int l = j + k; l < (int)cy.size(); l += j){
                            if(cy[l] != match){
                                good = false;
                                break;
                            }
                        }
                        if(good){
                            ans = min(ans, j);
                            break;
                        }
                    }
                    for(int k = 0; k < (int)cy.size() / j; k++){
                        int match = cy[k];
                        bool good = true;
                        for(int l = (int)cy.size() / j + k; l < (int)cy.size(); l += (int)cy.size() / j){
                            if(cy[l] != match){
                                good = false;
                                break;
                            }
                        }
                        if(good){
                            ans = min(ans, (int)cy.size() / j);
                            break;
                        }
                    }
                }
            }
        }
        moo << ans << endl;
    }
}
