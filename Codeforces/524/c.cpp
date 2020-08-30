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
    int N, K; cin >> N >> K;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    int Q; cin >> Q;
    while(Q--){
        int x; cin >> x;
        int ans = INT_MAX;
        for(int i = 1; i <= K; i++){
            for(int j = 0; j < N; j++){
                bool found = false;
                for(int k = i-1; k >= 0; k--){
                    int already = k * a[j];
                    int remain = x - already;
                    if(remain % (i-k) == 0){
                        if(binary_search(a, a+N, remain/(i-k))){
                            ans = min(ans, i);
                            found = true;
                            break;
                        }
                    }
                }
                if(found){
                    break;
                }
            }
        }
        cout << (ans == INT_MAX ? -1 : ans) << endl;
    }
    return 0;
}


