/*
ID: sireric1
TASK: ride
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)

int main(){
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string a, b; fin >> a >> b;
    int av = a[0] - 64, bv = b[0] - 64;
    FOR(i, 1, a.size())
        av *= a[i] - 64;
    FOR(i, 1, b.size())
        bv *= b[i] - 64;
    if(av % 47 == bv % 47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
