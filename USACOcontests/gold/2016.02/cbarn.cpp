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
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int N; cin >> N;
    int c[N];
    for(int i = 0; i < N; i++){
        cin >> c[i];   
    }
    int minN = INT_MAX;
    int minidx = 0;
    int runningcnt = 0;
    for(int i = 0; i < N; i++){
        runningcnt += c[i]-1;
        if(runningcnt < minN){
            minN = runningcnt;
            minidx = i;
        }
    }
    int start = (minidx+1)%N;
    ll ans = 0;
    queue<int> q;
    for(int i = 0; i < N; i++){
        int idx = (start+i)%N;
        for(int j = 0; j < c[idx]; j++){
            q.push(i);
        }
        int release = q.front();
        int diff = pow(i - release, 2);
        ans += diff;
        q.pop();
    }
    cout << ans << endl;
    return 0;
}


