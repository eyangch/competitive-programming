#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");
    long long N, T, ret = 0;
    fin >> N >> T;
    long long fpos[N];
    bool lead[N];
    fill(lead, lead + N, true);
    pair<long long, long long> cows[N];
    for(int i = 0; i < N; i++)
        fin >> cows[i].first >> cows[i].second;
    fpos[N-1] = cows[N-1].first + cows[N-1].second * T;
    for(int i = N-2; i >= 0; i--){
        fpos[i] = cows[i].first + cows[i].second * T;
        if(fpos[i] >= fpos[i+1]){
            lead[i] = false;
            fpos[i] = fpos[i+1];
        }
    }
    for(int i = 0; i < N; i++)
        if(lead[i])
            ret++;
    fout << ret << endl;
    return 0;
}
