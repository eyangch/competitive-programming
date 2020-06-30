#include <bits/stdc++.h>

using namespace std;
// default sort by seniority
bool c1(array<int, 3> a, array<int, 3> b){
    if(a[1] == b[1])
        return a[0] > b[0];
    return a[1] < b[1];
} // sort by time

int main(){
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");
    int N;
    fin >> N;
    array<int, 3> c[N];
    for(int i = 0; i < N; i++){
        c[i][0] = i;
        fin >> c[i][1] >> c[i][2];
    }
    sort(c, c + N, c1);
    long long mWait = 0, cTime = c[0][1], cowN = 1;
    set<array<int, 3>> line;
    line.insert(c[0]);
    for(int i = 0; i < N; i++){
        array<int, 3> cow = *line.begin();
        mWait = max(mWait, cTime - cow[1]);
        cTime += cow[2];
        line.erase(line.begin());
        while(c[cowN][1] <= cTime && cowN < N){
            line.insert(c[cowN]);
            cowN++;
        }
        if(line.empty()){
            line.insert(c[cowN]);
            cTime = c[cowN][1];
            cowN++;
        }
    }
    fout << mWait << endl;
}
