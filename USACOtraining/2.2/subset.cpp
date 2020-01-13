#include <bits/stdc++.h>

using namespace std;

int addupto(int N){
    int ret = 0;
    for(int i = 1; i < N+1; i++) ret += i;
    return ret;
}

int main(){
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    int N, total = 0, ret = 0;
    fin >> N;
    total = addupto(N);
    if(total % 2 == 1){
        fout << 0 << endl;
        return 0;
    }
    long long dp[N+1][total+1];
    fill(dp[0], dp[N] + total + 1, 0);
    dp[1][1] = 1;
    for(int i = 2; i < N+1; i++){
        copy(dp[i-1], dp[i-1] + total + 1, dp[i]);
        int uptill = addupto(i) + 1;
        dp[i][i]++;
        for(int j = i+1; j < uptill; j++)
            dp[i][j] += dp[i-1][j-i];
    }
    fout << dp[N][total/2]/2 << endl;
    return 0;
}
