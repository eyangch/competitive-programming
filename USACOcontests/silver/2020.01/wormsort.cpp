#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int n, m;
int p[100000];
pair<int, pii> wh[100000];

bool works(int x){
    if(x < 0){
        return false;
    }
    vi graph[n];
    for(int i = 0; i < x; i++){
        int a = wh[i].second.first;
        int b = wh[i].second.second;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int group[n];
    fill(group, group+n, -1);
    for(int i = 0; i < n; i++){
        if(group[i] != -1){
            continue;
        }
        queue<int> bfs;
        bfs.push(i);
        while(!bfs.empty()){
            int idx = bfs.front();
            bfs.pop();
            if(group[idx] != -1){
                continue;
            }
            group[idx] = i;
            for(int j : graph[idx]){
                bfs.push(j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(group[p[i]] != group[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout); 
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < m; i++){
        cin >> wh[i].second.first >> wh[i].second.second >> wh[i].first;
        wh[i].second.first--;
        wh[i].second.second--;
    }
    sort(wh, wh+m, greater<pair<int, pii>>());
    int low = 0;
    int high = m;
    int mid;
    while(low < high){
        mid = (low + high) / 2;
        bool ok = works(mid);
        bool ok1 = works(mid-1);
        if(ok && !ok1){
            break;
        }else if(ok){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    while(works(mid) && mid > 0){
        mid--;
    }
    while(!works(mid)){
        mid++;
    }
    if(mid == 0){
        cout << -1 << endl;
    }else{
        cout << wh[mid-1].first << endl;
    }
    return 0;
}
