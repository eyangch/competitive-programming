#include <bits/stdc++.h>

using namespace std;

bool chkzerosum(int N, vector<int> ops){
    int currn = 0;
    vector<int> parsedops;
    for(int i = 1; i < N; i++){
        currn *= 10;
        currn += i;
        if(ops[i-1] > 0){
            parsedops.push_back(currn);
            currn = 0;
        }
    }
    currn *= 10;
    currn += N;
    parsedops.push_back(currn);
    int sum = parsedops[0];
    int opidx = 0;
    for(int i = 1; i < parsedops.size(); i++){
        while(ops[opidx] == 0){
            opidx++;
        }
        int mp = 1;
        if(ops[opidx] == 2){
            mp = -1;
        }
        sum += mp * parsedops[i];
        opidx++;
    }
    if(sum == 0)
        return true;
    return false;
}

void dfs(int N, vector<int> ops){
    if(ops.size() == N-1){
        if(chkzerosum(N, ops)){
            for(int i = 0; i < N-1; i++){
                cout << i + 1;
                if(ops[i] == 0) cout << " ";
                else if(ops[i] == 1) cout << "+";
                else cout << "-";
            }
            cout << N << endl;
        }
    }else{
        for(int i = 0; i < 3; i++){
            vector<int> nxtops = ops;
            nxtops.push_back(i);
            dfs(N, nxtops);
        }
    }
}

int main(){
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    int N; cin >> N;
    vector<int> empt;
    dfs(N, empt);
    vector<int> test;
    return 0;
}
