#include <bits/stdc++.h>

using namespace std;

vector<bool> calcId(int N, bool c[1000], bool start){
    vector<bool> ret;
    for(int i = 0; i < N; i++)
        ret.push_back(abs(c[i] - c[0]));
    return ret;
}

int main(){
    ifstream fin("leftout.in");
    ofstream fout("leftout.out");
    int N, vertc = 0, horzc = 0;
    vector<bool> ids[1000], idsh[1000];
    bool c[1000][1000], ch[1000][1000];
    fin >> N;
    for(int i = 0; i < N; i++){
        string x;
        fin >> x;
        for(int j = 0; j < N; j++){
            if(x[j] == 'L'){
                c[i][j] = false;
                ch[j][i] = false;
            }else{
                c[i][j] = true;
                ch[j][i] = true;
            }
        }
    }
    unordered_map<vector<bool>, int> usedid;
    for(int i = 0; i < N; i++){
        ids[i] = calcId(N, c[i], c[i][0]);
        unordered_map<vector<bool>, int>::iterator it = usedid.find(ids[i]);
        if(it == usedid.end()){
            usedid.insert(make_pair(ids[i], 1));
            vertc++;
        }else
            it->second++;
    }
    if(vertc != 2){
        fout << -1 << endl;
        return 0;
    }
    int mindiff = INT_MAX;
    for(pair<vector<bool>, int> i : usedid)
        if(i.second < mindiff)
            mindiff = i.second;
    if(mindiff != 1){
        fout << -1 << endl;
        return 0;
    }
    unordered_map<vector<bool>, int> usedidh;
    for(int i = 0; i < N; i++){
        idsh[i] = calcId(N, ch[i], ch[i][0]);
        unordered_map<vector<bool>, int>::iterator it = usedidh.find(idsh[i]);
        if(it == usedid.end()){
            usedidh.insert(make_pair(idsh[i], 1));
            horzc++;
        }else
            it->second++;
    }
    if(horzc != 2){
        fout << -1 << endl;
        return 0;
    }
    mindiff = INT_MAX;
    for(pair<vector<bool>, int> i : usedidh)
        if(i.second < mindiff)
            mindiff = i.second;
    if(mindiff != 1){
        fout << -1 << endl;
        return 0;
    }
    int row;
    if(ids[0] != ids[1]){
        if(ids[0] == ids[2])
            row = 1;
        if(ids[1] == ids[2])
            row = 0;
    }else{
        for(int i = 2; i < N; i++){
            if(ids[i] != ids[0]){
                row = i;
                break;
            }
        }
    }
    fout << row + 1 << " ";
    int col;
    if(idsh[0] != idsh[1]){
        if(idsh[0] == idsh[2])
            col = 1;
        if(idsh[1] == idsh[2])
            col = 0;
    }else{
        for(int i = 2; i < N; i++){
            if(idsh[i] != idsh[0]){
                col = i;
                break;
            }
        }
    }
    fout << col + 1 << endl;
    return 0;
}
