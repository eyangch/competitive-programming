#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");
    int N, ret = 0;
    int pairs[26][26][26][26]; // cityLetter 1, cityLetter 2, stateLetter 1, stateLetter 2
    fin >> N;
    fill(pairs[0][0][0], pairs[25][25][25] + 26, 0);
    for(int i = 0; i < N; i++){
        string a, b;
        fin >> a >> b;
        pairs[a[0] - 65][a[1] - 65][b[0] - 65][b[1] - 65]++;
    }
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            for(int k = 0; k < 26; k++)
                for(int l = 0; l < 26; l++)
                    if(i != k || j != l)
                        ret += pairs[i][j][k][l] * pairs[k][l][i][j];
    fout << ret / 2 << endl;
    return 0;
}
