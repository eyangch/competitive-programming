#include <bits/stdc++.h>

using namespace std;

vector<int> n2vec(int N){
    vector<int> ret;
    int ndigits = (int)log10(N) + 1;
    for(int i = ndigits-1; i >= 0; i--){
        ret.push_back(N/pow(10, i));
        N %= (int)pow(10, i);
    }
    return ret;
}

int main(){
    ifstream fin("runround.in");
    ofstream fout("runround.out");
    int N, i;
    fin >> N;
    for(i = N + 1; i > N; i++){
        int m10;
        for(m10 = 1; i % (int)pow(10, m10) == 0; m10++){}
        if(m10 > 1)
            i += pow(10, m10-2);
        vector<int> nvec = n2vec(i);
        unordered_set<int> uniquetest;
        for(int j = 0; j < nvec.size(); j++)
            uniquetest.insert(nvec[j]);
        if(uniquetest.size() != nvec.size()) continue;
        unordered_set<int> already;
        int currentpos = 0;
        bool good = true;
        for(int j = 0; j < nvec.size(); j++){
            if(already.find(currentpos) != already.end()){
                good = false;
                break;
            }
            already.insert(currentpos);
            currentpos += nvec[currentpos];
            currentpos %= nvec.size();
        }
        if(currentpos == 0 && good) break;
    }
    fout << i << endl;
    return 0;
}
