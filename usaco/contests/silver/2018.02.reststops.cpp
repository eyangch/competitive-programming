#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

using namespace std;

int main(){
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");
    long long L, N, rF, rB, r, rAt = 0, ret = 0;
    array<long long, 100000> reststopDist, reststopTaste;
    fin >> L >> N >> rF >> rB;
    for(int i = 0; i < N; i++)
        fin >> reststopDist[i] >> reststopTaste[i];
    r = rF - rB;
    array<long long, 100000>::iterator it = max_element(reststopTaste.begin(), reststopTaste.begin() + N);
    int d = distance(reststopTaste.begin(), it);
    while(it != reststopTaste.begin() + N){
        ret += (reststopDist[d] - rAt) * r * reststopTaste[d];
        rAt = reststopDist[d];
        it = max_element(it + 1, reststopTaste.begin() + N);
        d = distance(reststopTaste.begin(), it);
    }
    fout << ret << endl;
    return 0;
}
