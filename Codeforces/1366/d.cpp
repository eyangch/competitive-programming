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

int sieve[10000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(sieve, sieve+10000001, 1);
    for(int i = 2; i < 10000001; i++){
        if(sieve[i] == 1){
            for(int j = 2 * i; j < 10000001; j+=i){
                if(sieve[j] == 1){
                    sieve[j] = i;   
                }
            }
        }
    }
    int N; cin >> N;
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    int ans[2][N];
    for(int i = 0; i < N; i++){
        unordered_set<int> pfac;
        int x = a[i];
        while(x > 1){
            if(sieve[x] == 1){
                pfac.insert(x);
                break;
            }
            pfac.insert(sieve[x]);
            x /= sieve[x];
        }
        if(pfac.size() <= 1){
            ans[0][i] = -1;
            ans[1][i] = -1;
        }else{
            ans[0][i] = *pfac.begin();
            int two = 1;
            for(int j : pfac){
                two *= j;
            }
            two /= *pfac.begin();
            ans[1][i] = two;
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


