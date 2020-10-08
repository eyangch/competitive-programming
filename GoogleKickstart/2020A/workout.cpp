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

int N, K, m[100000], gaps[100000];

bool ok(int mid){
    int ops = 0;
    for(int i = 0; i < N-1; i++){
        ops += (gaps[i]+mid-1)/mid-1;
    }
    return (ops <= K);
}

int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cout << "Case #" << tc << ": ";
        cin >> N >> K;
        for(int i = 0; i < N; i++){
            cin >> m[i];
        }
        for(int i = 1; i < N; i++){
            gaps[i-1] = m[i]-m[i-1];
        }
        int lo = 1, hi = 1e9, mid = 5;
        while(lo < hi){
            mid = (lo+hi)/2;
            if(ok(mid)){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        while(mid > 1 && ok(mid)){
            mid--;
        }
        while(!ok(mid)){
            mid++;
        }
        cout << mid << endl;
    }
    return 0;
}


