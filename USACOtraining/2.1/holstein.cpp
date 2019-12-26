#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
typedef vector<int> vi;

vi small;
int ismall, V, G, vt[25], f[15][25];

bool check(vi feeds){
    int va[25];
    fill(va, va + V, 0);
    FOR(i, 0, (int)feeds.size())
        FOR(j, 0, V)
            va[j] += f[feeds[i]][j];
    FOR(i, 0, V)
        if(va[i] < vt[i])
            return false;
    return true;
}

void calc(vi feeds, int fNum){
    feeds.push_back(fNum);
    cout << fNum << endl;
    if((int)feeds.size() >= ismall)
        return;
    if(check(feeds)){
        ismall = (int)feeds.size();
        small = feeds;
        return;
    }
    FOR(i, fNum + 1, G)
        calc(feeds, i);
    return;
}

int main(){
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    ismall = INT_MAX;
    fin >> V;
    FOR(i, 0, V)
        fin >> vt[i];
    fin >> G;
    FOR(i, 0, G)
        FOR(j, 0, V)
            fin >> f[i][j];
    FOR(i, 0, G){
        vi f;
        calc(f, i);
    }
    fout << ismall << " ";
    FOR(i, 0, ismall - 1)
        fout << small[i] + 1 << " ";
    fout << small[ismall-1] + 1 << endl;
    return 0;
}
