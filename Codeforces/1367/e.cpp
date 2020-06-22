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
        string s; cin >> s;
        vi ovec;
        map<char, int> omap;
        for(int i = 0; i < N; i++){
            omap[s[i]]++;   
        }
        for(auto it = omap.begin(); it != omap.end(); it++){
            ovec.push_back(it -> second);
        }
        sort(ovec.begin(), ovec.end(), greater<int>());
        int i;
        for(i = N; i > 0; i--){
            for(int j = 1; j <= min(i, K); j++){
                if(i % j == 0 && K % j == 0){
                    int add = 0;
                    for(int k = 0; k < min(j, (int)ovec.size()); k++){
                        add += ovec[k] / (i/j);
                    }
                    if(add >= j){
                        goto outexit;
                    }
                }
            }
        }
        outexit:
        cout << i << endl;
    }
    return 0;
}


