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

int w[2][26], s[2][26];

bool cmp(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 26; j++){
            if(w[i][j] != s[i][j]) return false;
        }
    }
    return true;
}

int main(){
    //freopen("writing.in", "r", stdin);
    //freopen("writing.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    string W, S; cin >> W >> S;
    for(int i = 0; i < N; i++){
        if(W[i] > 'Z'){
            w[1][W[i]-'a']++;
        }else{
            w[0][W[i]-'A']++;
        }
    }
    for(int i = 0; i < N; i++){
        if(S[i] > 'Z'){
            s[1][S[i]-'a']++;
        }else{
            s[0][S[i]-'A']++;
        }
    }
    int ans = cmp();
    for(int i = N; i < M; i++){
        if(S[i] > 'Z'){
            s[1][S[i]-'a']++;
        }else{
            s[0][S[i]-'A']++;
        }
        if(S[i-N] > 'Z'){
            s[1][S[i-N]-'a']--;
        }else{
            s[0][S[i-N]-'A']--;
        }
        ans += cmp();
    }
    cout << ans << endl;
    return 0;
}


