#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int N;
    array<int, 100000> mov;
    array<bool, 100000> gVisit;
    fin >> N;
    for(int i = 0; i < N; i++){
        fin >> mov[i];
        mov[i]--;
    }
    int loopN = 0;
    for(int i = 0; i < N; i++){
        if(gVisit[i]) continue;
        unordered_map<int, int> lVisit;
        int c = i;
        while(true){
            gVisit[c] = true;
            lVisit.insert(make_pair(c, lVisit.size()));
            c = mov[c];
            unordered_map<int, int>::iterator it = lVisit.find(c);
            if(it != lVisit.end()){
                loopN += lVisit.size() - it->second;
                break;
            }
            if(gVisit[c]) break;
        }
    }
    fout << loopN << endl;
    return 0;
}
