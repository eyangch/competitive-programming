#include <bits/stdc++.h>

using namespace std;

bool dance(int N, int T, int cows[10000], int K){
    int dancing[10000];
    for(int i = 0; i < K; i++)
        dancing[i] = cows[i];
    for(int i = K; i < N; i++){
        int sv = 2147483647, si = 0;
        for(int j = 0; j < K; j++){
            if(dancing[j] < sv){
                sv = dancing[j];
                si = j;
            }
        }
        dancing[si] = cows[i] + sv;
    }
    for(int i = 0; i < K; i++)
        if(dancing[i] > T)
            return false;
    return true;
}

int bAns(int N, int T, int cows[10000]){
    int lK = 1;
    int hK = N;
    int mK = (hK + lK) / 2;
    int r = 100000;
    while(lK <= hK){
        if(dance(N, T, cows, mK)){
            r = min(r, mK);
            hK = mK - 1;
        }else
            lK = mK + 1;
        mK = (hK + lK) / 2;
    }
    return r;
}

int main(){
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    int N, T, cows[10000];
    fin >> N >> T;
    for(int i = 0; i < N; i++)
        fin >> cows[i];
    fout << bAns(N, T, cows) << endl;
    return 0;
}
