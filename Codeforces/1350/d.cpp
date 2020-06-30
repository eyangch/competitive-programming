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
    while(T--){
        int N, K; cin >> N >> K;
        int a[N+1];
        int scores[N+1];
        a[0] = 0;
        bool foundK = false;
        for(int i = 1; i <= N; i++){
            cin >> a[i];   
            if(a[i] == K) foundK = true;
        }
        if(!foundK){
            cout << "no" << endl;
            continue;
        }if(N == 1){
            cout << "yes" << endl;
            continue;
        }
        scores[0] = 0;
        for(int i = 1; i <= N; i++){
            scores[i] = 0;
            if(a[i] < K){
                scores[i]--;
            }else if(a[i] > K){
                scores[i]++;
            }
        }
        bool good = false;
        for(int i = 0; i < N; i++){
            for(int j = 1; j < 3 && i + j < N; j++){
                if(scores[i+1] >= 0 && scores[i+j+1] >= 0){
                    good = true;
                    goto done;
                }
            }
        }
        done:
        if(good){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}


