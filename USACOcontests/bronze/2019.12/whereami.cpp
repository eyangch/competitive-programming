#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); i++)

int main(){
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int N;
    string x;
    fin >> N >> x;
    FOR(i, 0, N){
        unordered_set<string> already;
        FOR(j, 0, N-i+1){
            string p = x.substr(j, i);
            if(already.find(p) != already.end())
                break;
            already.insert(p);
            if(j == N - i){
                fout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}
