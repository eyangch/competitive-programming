#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int N, Q, breedC[100001][3], istr, istr2;
    fin >> N >> Q;
    fill(breedC[0], breedC[0] + 3, 0);
    for(int i = 1; i < N + 1; i++){
        fin >> istr;
        copy(breedC[i-1], breedC[i-1] + 3, breedC[i]);
        breedC[i][istr-1]++;
    }
    for(int i = 0; i < Q; i++){
        fin >> istr >> istr2;
        fout << breedC[istr2][0] - breedC[istr-1][0] << " " << breedC[istr2][1] - breedC[istr-1][1] << " " << breedC[istr2][2] - breedC[istr-1][2] << endl;
    }
    return 0;
}
