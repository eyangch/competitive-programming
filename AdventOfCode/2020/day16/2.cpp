#include <bits/stdc++.h>

using namespace std;

bool have[2000];
vector<int> h[2000];
set<int> via[2000];
vector<vector<int>> v;

signed main(){
    freopen("input.txt", "r", stdin);
    string nxt;
    int mode = 0;
    long long ans = 1;
    int cnt = 0;
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
                h[i].push_back(cnt);
            }
            for(int i = n3; i <= n4; i++){
                have[i] = true;
                h[i].push_back(cnt);
            }
            cnt++;
        }else if(mode == 1 || mode == 2){
            vector<int> vc;
            int pv = 0;
            bool good = true; 
            for(int i = 0; i < (int)nxt.size(); i++){
                if(nxt[i] == ','){
                    int x = stoi(nxt.substr(pv, i-pv));
                    if(!have[x]) good = false;
                    vc.push_back(x);
                    pv = i+1;
                }
            }
            int y = stoi(nxt.substr(pv));
            if(!have[y]) good = false;
            vc.push_back(y);
            if(good){
                v.push_back(vc);
            }
        }
    }
    int M = (int)v[0].size();
    int N = (int)v.size();
    for(int i = 0; i < M; i++){
        for(int j = 0; j < 2000; j++){
            via[i].insert(j);
        }
        for(int j = 0; j < N; j++){
            set<int> curr;
            for(int k : h[v[j][i]]){
                curr.insert(k);
            }
            vector<int> rm;
            for(int j : via[i]){
                if(!curr.count(j)){
                    rm.push_back(j);
                }
            }
            for(int j : rm){
                via[i].erase(j);
            }
        }
        
    }
    int tick[50];
    for(int op = 0; op < M; op++){
        int rm = 0;
        int id = 0;
        for(int i = 0; i < M; i++){
            if((int)via[i].size() == 1){
                rm = *via[i].begin();
                id = i;
                break;
            }
        }
        for(int i = 0; i < M; i++){
            via[i].erase(rm);
        }
        tick[rm] = v[0][id];
    }
    for(int i = 0; i < 6; i++){
        ans *= tick[i];
    }
    cout << ans << endl;
}
