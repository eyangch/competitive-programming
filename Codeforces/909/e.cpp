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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    bool E[N];
    for(int i = 0; i < N; i++){
        cin >> E[i];   
    }
    vi graph[N];
    int indeg[N];
    fill(indeg, indeg+N, 0);
    for(int i = 0; i < M; i++){
        int t1, t2; cin >> t1 >> t2;
        graph[t2].push_back(t1);
        indeg[t1]++;
    }
    queue<int> main, co;
    for(int i = 0; i < N; i++){
        if(indeg[i] == 0){
            if(E[i]){
                co.push(i);
            }else{
                main.push(i);
            }
        }
    }
    int cnt = 0;
    while(!(main.empty() && co.empty())){
        while(!main.empty()){
            int idx = main.front();
            main.pop();
            for(int i : graph[idx]){
                indeg[i]--;
                if(indeg[i] == 0){
                    if(E[i]){
                        co.push(i);
                    }else{
                        main.push(i);
                    }
                }
            }
        }
        if(!co.empty()){
            cnt++;
        }
        while(!co.empty()){
            int idx = co.front();
            co.pop();
            for(int i : graph[idx]){
                indeg[i]--;
                if(indeg[i] == 0){
                    if(E[i]){
                        co.push(i);
                    }else{
                        main.push(i);
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}


