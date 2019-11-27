#include <bits/stdc++.h>

using namespace std;

int rec(vector<pair<bool, int>> p[100000], bool (&vst)[100000], int field, int stypes[100000]){
    if(vst[field]) return 0;
    vst[field] = true;
    for(unsigned int i = 0; i < p[field].size(); i++){
        int mp;
        if(p[field][i].first == true)
            mp = -1;
        else
            mp = 1;
        if(stypes[p[field][i].second] == 0)
            stypes[p[field][i].second] = stypes[field] * mp;
        else
            if(stypes[p[field][i].second] != stypes[field] * mp)
                return -1;
        if(rec(p, vst, p[field][i].second, stypes) == -1)
            return -1;
    }
    return 1;
}

int main(){
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    int N, M, ret = 1, stypes[100000];;
    fin >> N >> M;
    vector<pair<bool, int>> p[100000];
    bool vst[100000];
    fill(begin(stypes), begin(stypes) + N, 0);
    fill(begin(vst), begin(vst) + N, false);
    for(int i = 0; i < M; i++){
        char sd;
        pair<int, int> past;
        bool sdb;
        fin >> sd >> past.first >> past.second;
        if(sd == 'S') sdb = false;
        else sdb = true;
        p[past.first - 1].push_back(make_pair(sdb, past.second - 1));
        p[past.second - 1].push_back(make_pair(sdb, past.first - 1));
    }
    for(int i = 0; i < N; i++){
        stypes[i] = 1;
        int x = rec(p, vst, i, stypes);
        stypes[i] = 0;
        if(x == -1){
            fout << 0 << endl;
            return 0;
        }
        ret += x;
    }
    string binret;
    binret += '1';
    for(int i = 0; i < ret - 1; i++)
        binret += '0';
    fout << binret << endl;
    return 0;
}
