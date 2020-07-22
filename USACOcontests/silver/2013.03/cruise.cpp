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
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    int N, M, K; cin >> N >> M >> K;
    pii lr[N];
    int go[N];
    for(int i = 0; i < N; i++){
        cin >> lr[i].first >> lr[i].second;  
        lr[i].first--; lr[i].second--;
        go[i] = i; 
    }
    for(int i = 0; i < M; i++){
        char turn; cin >> turn;
        for(int j = 0; j < N; j++){
            if(turn == 'L'){
                go[j] = lr[go[j]].first;
            }else{
                go[j] = lr[go[j]].second;
            }
        }
    }
    // super cool tortoise and hare fell asleep and the tortoise caught up but they are really confusing so im not implmenting it
    map<int, int> been;
    int ptr = 0;
    int total = 0;
    for(; true; total++){
        if(total == K){
            cout << ptr+1 << endl;
            return 0;
        }
        if(been.find(ptr) != been.end()){
            break;
        }
        been[ptr] = total;
        ptr = go[ptr];
    }
    int before = been[ptr];
    int cyclelen = total - been[ptr];
    K -= before;
    int cycidx = K % cyclelen;
    for(auto it = been.begin(); it != been.end(); it++){
        if(it -> second == before + cycidx){
            cout << it -> first + 1 << endl;
        }
    }
    return 0;
}


