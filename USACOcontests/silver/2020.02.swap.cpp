#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    int N, M, K;
    fin >> N >> M >> K;
    int l[M], r[M];
    for(int i = 0; i < M; i++){
        fin >> l[i] >> r[i];
    }
    int cowpos[N], changePos[N], finalPos[N];
    for(int i = 0; i < N; i++){
        cowpos[i] = i;
    }
    for(int i = 0; i < M; i++){
        reverse(cowpos + l[i] - 1, cowpos + r[i]);
    }
    for(int i = 0; i < N; i++){
        changePos[cowpos[i]] = i;
    }
    bool visited[N];
    fill(visited, visited + N, false);
    for(int i = 0; i < N; i++){
        if(visited[i]){
            continue;
        }
        vector<int> loop;
        int curr = i;
        do{
            loop.push_back(curr);
            visited[curr] = true;
            curr = changePos[curr];
        }while(curr != i);
        for(int i = 0; i < loop.size(); i++){
            finalPos[loop[(i + K) % loop.size()]] = loop[i] + 1;
        }
    }
    for(int i = 0; i < N; i++){
        fout << finalPos[i] << endl;
    }
    return 0;
}
