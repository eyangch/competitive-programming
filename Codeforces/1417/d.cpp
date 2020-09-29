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

struct op{
    int a;
    int b;
    int c;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N; cin >> N;
        int a[N];
        int sum = 0;
        for(int i = 0; i < N; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % N != 0){
            cout << -1 << endl;
            continue;
        }
        int targ = sum / N;
        vector<op> ops;
        op tmp;
        for(int i = 1; i < N; i++){
            int remain = a[i] % (i+1);
            int addremain = i+1-remain;
            if(a[0] >= addremain){
                tmp = {1, i+1, addremain};
                ops.push_back(tmp);
                a[0] -= addremain;
                a[i] += addremain;
            }
            tmp = {i+1, 1, a[i] / (i+1)};
            ops.push_back(tmp);
            a[0] += a[i] / (i+1) * (i+1);
            a[i] = a[i] % (i+1);
        }
        bool done[N];
        fill(done, done+N, false);
        for(int i = 1; i < N; i++){
            if(a[i] > targ){
                int remain = a[i] % (i+1);
                int addremain = i+1-remain;
                tmp = {1, i+1, addremain};
                ops.push_back(tmp);
                a[i] += addremain;
                a[0] -= addremain;
                tmp = {i+1, 1, a[i]/(i+1)};
                ops.push_back(tmp);
                a[0] += a[i];
                a[i] = 0;
            }
        }
        for(int i = 1; i < N; i++){
            if(a[i] < targ){
                tmp = {1, i+1, targ - a[i]};
                ops.push_back(tmp);
            }
        }
        cout << ops.size() << endl;
        for(op i : ops){
            cout << i.a << " " << i.b << " " << i.c << endl;
        }
    }
    return 0;
}


