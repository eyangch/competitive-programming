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
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N, K; cin >> N >> K;
        int a[N];
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }
        for(int i = 0; i < N; i++){
            int x; cin >> x;
        }
        sort(a, a+N);
        multiset<int> ms;
        int ptr = 0;
        int score[N];
        int fin[N];
        for(int i = 0; i < N; i++){
            while(ptr < N && a[i] + K >= a[ptr]){
                ms.insert(a[ptr]);
                ptr++;
            }
            score[i] = (int)ms.size();
            fin[i] = ptr;
            ms.erase(ms.find(a[i]));
        }
        int rpfx[N];
        rpfx[N-1] = score[N-1];
        for(int i = N-2; i >= 0; i--){
            rpfx[i] = max(rpfx[i+1], score[i]);
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            ans = max(ans, score[i]);
        }
        for(int i = 0; i < N; i++){
            if(fin[i] >= N) break;
            ans = max(ans, score[i] + rpfx[fin[i]]);
        }
        cout << ans << endl;
    }
    return 0;
}


