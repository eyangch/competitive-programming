#include <bits/stdc++.h>

using namespace std;

int test(int N, int bales[], int r, int K){
    int start = 0;
    for(int i = 0; i < K; i++){
        int e = start;
        while(bales[e] - bales[start] <= r * 2)
            e++;
        start = e;
        if(start > N-1)
            return true;
    }
    return false;
}

int binSearch(int N, int bales[], int K){
    int l = bales[0], h = bales[N-1], m = 0, ret = INT_MAX;
    while(l <= h){
        m = (l + h) / 2;
        if(test(N, bales, m, K)){
            ret = min(ret, m);
            h = m - 1;
        }else
            l = m + 1;
    }
    return ret;
}

int main(){
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int N, K, bales[50000];
    fin >> N >> K;
    for(int i = 0; i < N; i++)
        fin >> bales[i];
    sort(bales, bales + N);
    fout << binSearch(N, bales, K) << endl;
    return 0;
}
