#include <bits/stdc++.h>

using namespace std;

bool customCmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    int N;
    fin >> N;
    pair<int, int> bases[100000];
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        bases[i].first = a - b;
        bases[i].second = a + b;
    }
    sort(bases, bases + N, customCmp);
    int maxE = INT_MIN, ret = 0;
    for(int i = 0; i < N; i++){
        if(maxE < bases[i].second){
            ret++;
            maxE = bases[i].second;
        }
    }
    fout << ret << endl;
}
