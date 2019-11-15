#include <bits/stdc++.h>

using namespace std;

int srch(int N, int cows[1000], int target){
    for(int i = 0; i < N; i++)
        if(cows[i] == target)
            return i;
    return -1;
}

int diff(int x, int y, int N){
    if(y < x)
        y += N;
    return (y - x) * (y - x);
}

void dfs(int N, int (&rooms)[1000], int (&cows)[1000], int loc){
    int lcow = srch(N, cows, loc), nloc = loc + 1;
    nloc %= N;
    while(rooms[nloc] != 0)
        dfs(N, rooms, cows, nloc);
    rooms[loc]--;
    rooms[nloc]++;
    cows[lcow] = nloc;
}

int main(){
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int N, rooms[1000], cows[1000], origcowpos[1000], ct = 0, ans = 0;
    fin >> N;
    for(int i = 0; i < N; i++){
        fin >> rooms[i];
        for(int j = 0; j < rooms[i]; j++){
            cows[ct] = i;
            origcowpos[ct] = i;
            ct++;
        }
    }
    for(int i = 0; i < N; i++)
        while(rooms[i] > 1)
            dfs(N, rooms, cows, i);
    for(int i = 0; i < N; i++)
        ans += diff(origcowpos[i], cows[i], N);
    fout << ans << endl;
    return 0;
}
