#include <bits/stdc++.h>
#define f first
#define s second

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
    int N; cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    queue<int> n1, n23;
    for(int i = 0; i < N; i++){
        if(a[i] == 1){
            n1.push(i);
        }
        if(a[i] == 2 || a[i] == 3){
            n23.push(i);
        }
    }
    vector<pii> pos;
    bool vis[100000];
    fill(vis, vis+N, false);
    for(int i = 0; i < N; i++){
        if(a[i] == 0 || vis[i]) continue;
        while(!n1.empty() && n1.front() <= i){
            n1.pop();
        }
        while(!n23.empty() && n23.front() <= i){
            n23.pop();
        }
        if(a[i] == 1){
            pos.push_back(pii(i, i));
        }else if(a[i] == 2){
            if(n1.empty()){
                cout << -1 << endl;
                return 0;
            }
            int nxt = n1.front();
            n1.pop();
            pos.push_back(pii(i, i));
            pos.push_back(pii(i, nxt));
            vis[nxt] = true;
        }else if(a[i] == 3){
            if(n23.empty()){
                if(n1.empty()){
                    cout << -1 << endl;
                    return 0;
                }
                int nxt = n1.front();
                n1.pop();
                pos.push_back(pii(i, i));
                pos.push_back(pii(i, nxt));
            }else{
                int nxt = n23.front();
                n23.pop();
                pos.push_back(pii(i, i));
                pos.push_back(pii(i, nxt));
            }
        }
    }
    cout << pos.size() << endl;
    for(pii i : pos){
        cout << i.f+1 << " " << i.s+1 << endl;
    }
    return 0;
}


