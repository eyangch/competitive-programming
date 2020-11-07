#include <bits/stdc++.h>
#define f first
#define s second
#define int long long

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

int N, a[200000];
vi graph[200000];
int leaves[200000], mx[200000], def[200000];

void dfs(int id){
    for(int i : graph[id]){
        dfs(i);
        if(mx[id] == mx[i]){
            def[id] += def[i];
        }else if(mx[id] > mx[i]){
            def[id] += def[i] + (mx[id] - mx[i]) * leaves[i];
        }else{
            def[id] += def[i] + (mx[i] - mx[id]) * leaves[id];
            mx[id] = mx[i];
        }
        leaves[id] += leaves[i];
    }
    if((int)graph[id].size() == 0){
        leaves[id] = 1;
        mx[id] = a[id];
        def[id] = 0;
    }else{
        if(def[id] >= a[id]){
            def[id] -= a[id];
        }else{
            a[id] -= def[id];
            def[id] = 0;
            int aplus = a[id] / leaves[id];
            mx[id] += aplus;
            int ndef = a[id] % leaves[id];
            if(ndef > 0){
                mx[id]++;
                def[id] = leaves[id] - ndef;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N;
    for(int i = 1; i < N; i++){
        int p; cin >> p;
        graph[p-1].push_back(i);
    }
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    dfs(0);
    cout << mx[0] << endl;
    return 0;
}


