#include <bits/stdc++.h>

using namespace std;

int getCast(array<vector<int>, 200> reach, int cow, array<int, 200> &castable, unordered_set<int> &been, unordered_set<int> &lbeen){
    if(lbeen.find(cow) != lbeen.end())
        return 0;
    been.insert(cow);
    lbeen.insert(cow);
    int reachable = 1;
    for(int i : reach[cow])
        reachable += getCast(reach, i, castable, been, lbeen);
    castable[cow] = reachable;
    return reachable;
}

int main(){
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    array<vector<int>, 200> reach;
    array<array<int, 3>, 200> cows;
    array<int, 200> castable;
    unordered_set<int> been;
    int N, ret = 0;
    fin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            fin >> cows[i][j];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j)
                continue;
            if(sqrt(pow(cows[i][0] - cows[j][0], 2) + pow(cows[i][1] - cows[j][1], 2)) <= cows[i][2])
                reach[i].push_back(j);
        }
    }
    for(int i = 0; i < N; i++){
        if(been.find(i) != been.end())
            continue;
        unordered_set<int> empt;
        ret = max(ret, getCast(reach, i, castable, been, empt));
    }
    fout << ret << endl;
    return 0;
}
