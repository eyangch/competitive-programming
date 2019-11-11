#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    int cows[3], maxc, minc;
    fin >> cows[0] >> cows[1] >> cows[2];
    if(cows[1] - cows[0] < cows[2] - cows[1]){
        minc = cows[1] - cows[0];
        maxc = cows[2] - cows[1];
    }
    else{
        minc = cows[2] - cows[1];
        maxc = cows[1] - cows[0];
    }
    if(minc == 2) fout << 1 << endl;
    else if(maxc == 1) fout << 0 << endl;
    else fout << 2 << endl;
    fout << maxc - 1 << endl;
    return 0;
}
