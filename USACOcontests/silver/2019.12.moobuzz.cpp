#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("moobuzz.in");
    ofstream fout("moobuzz.out");
    int N, ns[8] = {1, 2, 4, 7, 8, 11, 13, 14};
    fin >> N;
    int n1 = N / 8;
    cout << n1 << endl;
    int n2 = n1 * 15;
    if(N % 8 == 0){
        fout << n2 - 15 + ns[7];
    }else{
        fout << n2 + ns[N % 8 - 1] << endl;
    }
    return 0;
}
