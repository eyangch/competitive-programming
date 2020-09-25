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

struct state{
    pii c;
    int x;
    int d;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    int N; cin >> N;
    pii L, B; cin >> L.f >> L.s >> B.f >> B.s;
    pii m[N+1];
    pii mx[N+1], my[N+1];
    m[N] = mx[N] = my[N] = B;
    swap(my[N].f, my[N].s);
    for(int i = 0; i < N; i++){
        cin >> m[i].f >> m[i].s;
        my[i] = mx[i] = m[i];
        swap(my[i].f, my[i].s);
    }
    N++;
    sort(mx, mx+N);
    sort(my, my+N);
    state nxt;
    queue<state> q;
    nxt = {L, -1, 0};
    q.push(nxt);
    while(!q.empty()){
        pii c = q.front().c;
        int x = q.front().x, d = q.front().d;
        q.pop();
        //cout << c << " " << x << " "<< d << endl;
        if(c == B){
            cout << d-1 << endl;
            return 0;
        }
        if(x != 0){
            auto lb = lower_bound(mx, mx+N, pii(c.f, 0));
            while(lb - mx < N && (*lb).f == c.f){
                pii cur = *lb;
                if(cur == c){
                    lb++;
                    continue;
                }
                nxt = {cur, 0, d+1};
                q.push(nxt);
                lb++;
            }
        }
        if(x != 1){
            auto lb = lower_bound(my, my+N, pii(c.s, 0));
            while(lb - my < N && (*lb).f == c.s){
                pii cur = *lb;
                swap(cur.f, cur.s);
                if(cur == c){
                    lb++;
                    continue;
                }
                nxt = {cur, 1, d+1};
                q.push(nxt);
                lb++;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}


