#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

int N;
vi a;

signed main(){
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int x;
    while(cin >> x){
        N++;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int idx = lower_bound(a.begin(), a.end(), 2020-a[i]-a[j]) - a.begin();
            if(idx == N || idx == i || idx == j || a[i] + a[j] + a[idx] != 2020){
                continue;
            }
            cout << a[i] * a[j] * a[idx] << endl;
        }
    }
    return 0;
}


