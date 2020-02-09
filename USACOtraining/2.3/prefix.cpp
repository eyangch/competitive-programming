/*
ID: sireric1
TASK: prefix
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    vector<string> prim;
    string seq;
    int ret = 0;
    ios_base::sync_with_stdio(false);
    while(true){
        string x;
        fin >> x;
        if(x.compare(".") == 0){
            break;
        }
        prim.push_back(x);
    }
    while(true){
        string x;
        fin >> x;
        if(fin.eof()){
            break;
        }
        seq.append(x);
    }
    set<int> q;
    q.insert(0);
    while(!q.empty()){
        int curat = *(q.begin());
        q.erase(q.begin());
        ret = max(ret, curat);
        for(int i = 0; i < prim.size(); i++){
            if(prim[i].compare(seq.substr(curat, prim[i].length())) == 0){
                q.insert(curat + prim[i].length());
            }
        }
    }
    fout << ret << endl;
    return 0;
}
