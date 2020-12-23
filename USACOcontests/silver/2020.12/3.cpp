#include <bits/stdc++.h>

using namespace std;

int N;
char dir[1000];
int x[1000], y[1000];
vector<int> nc, ec;
bool stopped[1000];

vector<int> graph[1000];
int children[1000];

bool cmpn(int a, int b){
    return x[a] < x[b];
}
bool cmpe(int a, int b){
    return y[a] < y[b];
}

int dfs(int id){
    if(children[id]) return children[id];
    children[id] = 1;
    for(int i : graph[id]){
        children[id] += dfs(i);
    }
    return children[id];
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> dir[i] >> x[i] >> y[i];
    }
    for(int i = 0; i < N; i++){
        if(dir[i] == 'N'){
            nc.push_back(i);
        }else{
            ec.push_back(i);
        }
    }
    sort(nc.begin(), nc.end(), cmpn);
    sort(ec.begin(), ec.end(), cmpe);
    for(int i : nc){
        for(int j : ec){
            if(stopped[j]) continue;
            if(x[i] < x[j] || y[i] > y[j]){
                continue;
            }
            int reachy = y[j] - y[i];
            int reachx = x[i] - x[j];
            if(reachy < reachx){
                stopped[j] = true;
                graph[i].push_back(j);
            }else if(reachx < reachy){
                graph[j].push_back(i);
                break;
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << dfs(i)-1 << endl;
    }
}
