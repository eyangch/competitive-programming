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
int x[200000];
int d[1000001];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i];
        d[x[i]]++;
    }
    for(int i = 1000000; i > 0; i--){
        int curr = 0;
        for(int j = 1; i * j <= 1000000; j++){
            curr += d[i * j];
            if(curr > 1){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << "my code did an oops" << endl;
    return 0;
}


