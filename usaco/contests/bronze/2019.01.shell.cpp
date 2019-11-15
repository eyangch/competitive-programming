#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int N, s[4], sw[100][3], m = 0;
    fin >> N;
    for(int i = 0; i < N; i++)
        fin >> sw[i][0] >> sw[i][1] >> sw[i][2];
    for(int i = 1; i < 4; i++){
        int tm = 0;
        for(int j = 1; j < 4; j++) s[j] = 0;
        s[i] = 1;
        for(int j = 0; j < N; j++){
            swap(s[sw[j][0]], s[sw[j][1]]);
            if(s[sw[j][2]] == 1) tm++;
        }
        m = max(tm, m);
    }
    fout << m << endl;
}
