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
        sort(s.begin(), s.end());
        map<char, int> maps;
        for(int i = 0; i < N; i++){
            maps[s[i]]++;
        }
        auto sit = maps.begin();
        sit++;
        if(maps.begin() -> second < K){
            cout << s[K-1] << endl;
        }
        else if(maps.size() == 1 || (maps.size() == 2 && maps.begin() -> second == K)){
            string out[K];
            for(int i = 0; i < N; i++){
                out[i % K] += s[i];
            }
            sort(out, out+K);
            cout << out[K-1] << endl;
        }else{
            cout << s[0] + s.substr(K, string::npos) << endl;
        }
    }
    return 0;
}


