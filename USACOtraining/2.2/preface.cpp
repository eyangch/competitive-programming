#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    int N, rnums[7]; // I, V, X, L, C, D, M
    char r[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    fill(rnums, rnums + 7, 0);
    fin >> N;
    for(int i = 1; i < N+1; i++){
        int num = i;
        if(num >= 1000){
            rnums[6] += num / 1000;
            num %= 1000;
        }if(num >= 900){
            rnums[6]++;
            rnums[4]++;
            num %= 900;
        }if(num >= 500){
            rnums[5] += num / 500;
            num %= 500;
        }if(num >= 400){
            rnums[5]++;
            rnums[4]++;
            num %= 400;
        }if(num >= 100){
            rnums[4] += num / 100;
            num %= 100;
        }if(num >= 90){
            rnums[4]++;
            rnums[2]++;
            num %= 90;
        }if(num >= 50){
            rnums[3] += num / 50;
            num %= 50;
        }if(num >= 40){
            rnums[3]++;
            rnums[2]++;
            num %= 40;
        }if(num >= 10){
            rnums[2] += num / 10;
            num %= 10;
        }if(num >= 9){
            rnums[2]++;
            rnums[0]++;
            num %= 9;
        }if(num >= 5){
            rnums[1] += num / 5;
            num %= 5;
        }if(num >= 4){
            rnums[1]++;
            rnums[0]++;
            num %= 4;
        }if(num >= 1){
            rnums[0] += num;
        }
    }
    int stop = 7;
    for(; rnums[stop-1] == 0; stop--){}
    //cout << stop << endl;
    for(int i = 0; i < stop; i++){
        fout << r[i] << " " << rnums[i] << endl;
    }
    return 0;
}
