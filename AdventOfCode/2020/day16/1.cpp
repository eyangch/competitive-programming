#include <bits/stdc++.h>

using namespace std;

bool have[2000];

signed main(){
    freopen("input.txt", "r", stdin);
    string nxt;
    int mode = 0;
    int ans = 0;
    while(getline(cin, nxt)){
        if(nxt == ""){
            continue;
        }
        if(nxt == "your ticket:"){
            mode = 1;
            continue;
        }
        if(nxt == "nearby tickets:"){
            mode = 2;
            continue;
        }
        if(mode == 0){
            int fn = 0;
            for(; true; fn++){
                if(nxt[fn] >= '0' && nxt[fn] <= '9'){
                    break;
                }
            }
            int fne = fn;
            for(; true; fne++){
                if(nxt[fne] == '-'){
                    break;
                }
            }
            int n1 = stoi(nxt.substr(fn, fne-fn));
            fne++;
            int fn3 = fne;
            for(; true; fn3++){
                if(nxt[fn3] == ' '){
                    break;
                }
            }
            int n2 = stoi(nxt.substr(fne, fn3-fne));
            fn3 += 4;
            int fn4 = fn3;
            for(; true; fn4++){
                if(nxt[fn4] == '-'){
                    break;
                }
            }
            int n3 = stoi(nxt.substr(fn3, fn4-fn3));
            fn4++;
            int n4 = stoi(nxt.substr(fn4));
            for(int i = n1; i <= n2; i++){
                have[i] = true;
            }
            for(int i = n3; i <= n4; i++){
                have[i] = true;
            }
        }else if(mode == 1 || mode == 2){
            int pv = 0;
            for(int i = 0; i < (int)nxt.size(); i++){
                if(nxt[i] == ','){
                    int x = stoi(nxt.substr(pv, i-pv));
                    ans += (!have[x]) * x;
                    pv = i+1;
                }
            }
            int y = stoi(nxt.substr(pv));
            ans += (!have[y]) * y;
        }
    }
    cout << ans << endl;
}
