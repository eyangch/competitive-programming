/*
ID: sireric1
LANG: C++11
TASK: shuttle
*/

#include <bits/stdc++.h>

using namespace std;

int N;
int len;
string pz, target;
set<long long> vis;
set<long long> dist[100000];

long long shash(string s){
    long long ret = 0;
    long long pw = 1;
    for(char i : s){
        if(i == 'W') ret += 2LL*pw;
        if(i == 'B') ret += pw;
        pw *= 3LL;
    }
    return ret;
}

int32_t main(){
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
    cin >> N;
    for(int i = 0; i < N; i++){
        pz += 'B';
        target += 'W';
    }
    pz += '_';
    target += '_';
    for(int i = 0; i < N; i++){
        pz += 'W';
        target += 'B';
    }
    len = pz.size();
    queue<pair<string, int>> q;
    q.push({pz, 0});
    vis.insert(shash(pz));
    int fd = 0;
    while(!q.empty()){
        string cur = q.front().first;
        int d = q.front().second;
        q.pop();
        dist[d].insert(shash(cur));
        if(cur == target){
            fd = d;
            break;
        }
        int hloc = 0;
        for(; hloc < len && cur[hloc] != '_'; hloc++){}
        if(hloc - 2 >= 0 && cur[hloc-2] == 'B' && cur[hloc-2] != cur[hloc-1]){
            string nxt = cur;
            swap(nxt[hloc-2], nxt[hloc]);
            if(!vis.count(shash(nxt))){
                vis.insert(shash(nxt));
                q.push({nxt, d+1});
            }
        }
        if(hloc - 1 >= 0 && cur[hloc-1] == 'B'){
            string nxt = cur;
            swap(nxt[hloc-1], nxt[hloc]);
            if(!vis.count(shash(nxt))){
                vis.insert(shash(nxt));
                q.push({nxt, d+1});
            }
        }
        if(hloc + 1 < len && cur[hloc+1] == 'W'){
            string nxt = cur;
            swap(nxt[hloc], nxt[hloc+1]);
            if(!vis.count(shash(nxt))){
                vis.insert(shash(nxt));
                q.push({nxt, d+1});
            }
        }
        if(hloc + 2 < len && cur[hloc+2] == 'W' && cur[hloc+1] != cur[hloc+2]){
            string nxt = cur;
            swap(nxt[hloc], nxt[hloc+2]);
            if(!vis.count(shash(nxt))){
                vis.insert(shash(nxt));
                q.push({nxt, d+1});
            }
        }
    }
    queue<int> ans;
    string c = target;
    while(c != pz){
        fd--;
        int hloc = 0;
        for(; hloc < len && c[hloc] != '_'; hloc++){}
        if(hloc - 2 >= 0 && c[hloc-2] == 'W' && c[hloc-2] != c[hloc-1]){
            string nxt = c;
            swap(nxt[hloc-2], nxt[hloc]);
            if(dist[fd].count(shash(nxt))){
                ans.push(hloc - 2);
                c = nxt;
                continue;
            }
        }
        if(hloc - 1 >= 0 && c[hloc-1] == 'W'){
            string nxt = c;
            swap(nxt[hloc-1], nxt[hloc]);
            if(dist[fd].count(shash(nxt))){
                ans.push(hloc-1);
                c = nxt;
                continue;
            }
        }
        if(hloc + 1 < len && c[hloc+1] == 'B'){
            string nxt = c;
            swap(nxt[hloc], nxt[hloc+1]);
            if(dist[fd].count(shash(nxt))){
                ans.push(hloc+1);
                c = nxt;
                continue;
            }
        }
        if(hloc + 2 < len && c[hloc+2] == 'B' && c[hloc+1] != c[hloc+2]){
            string nxt = c;
            swap(nxt[hloc], nxt[hloc+2]);
            if(dist[fd].count(shash(nxt))){
                ans.push(hloc+2);
                c = nxt;
                continue;
            }
        }
    }
    int cnt = 0;
    while(!ans.empty()){
        cout << ans.front()+1 << (++cnt % 20 == 0 || (int)ans.size() == 1 ? "\n" : " ");
        ans.pop();
    }
}
