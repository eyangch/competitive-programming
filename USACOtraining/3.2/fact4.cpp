/*
ID: sireric1
LANG: C++11
TASK: fact4
*/

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
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
    int N; cin >> N;
    int sieve[4220];
    fill(sieve, sieve+4220, -1);
    for(int i = 2; i < 4220; i++){
        if(sieve[i] == -1){
            for(int j = 2 * i; j < 4220; j += i){
                sieve[j] = i;
            }
        }
    }
    int pfactors[4220];
    fill(pfactors, pfactors+4220, 0);
    for(int i = 2; i <= N; i++){
        int num = i;
        for(int j = 2; j <= N; j++){
            while(sieve[j] == -1 && num % j == 0){
                pfactors[j]++;
                num /= j;
            }
        }
    }
    int ans = 1;
    for(int i = 2; i < 4220; i++){
        int itnum = pfactors[i];
        if(i == 2 || i == 5){
            itnum -= min(pfactors[2], pfactors[5]);
        }
        for(int j = 0; j < itnum; j++){
            ans *= i;
            ans %= 10;
        }
    }
    cout << ans << endl;
    return 0;
}


