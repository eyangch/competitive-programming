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
    int N; cin >> N;
    bool sieve[200001];
    fill(sieve, sieve + 200001, true);
    vector<int> vsieve;
    for(int i = 2; i <= 200000; i++){
        if(sieve[i]){
            vsieve.push_back(i);
        }
        for(int j = 2 * i; j <= 200000; j += i){
            sieve[j] = false;
        }
    }
    int a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    ll ans = 1;
    for(int i : vsieve){
        int min1 = 10000000, min2 = 10000000;
        int cnt = 0;
        for(int j : a){
            if(j % i != 0){
                cnt++;
                if(cnt >= 2){
                    break;
                }
                continue;
            }
            int curr = 0;
            while(j % i == 0){
                curr++;
                j /= i;
            }
            if(curr < min1){
                min2 = min1;
                min1 = curr;
            }else if(curr < min2){
                min2 = curr;
            }
        }
        if(cnt >= 2){
            continue;
        }else if(cnt == 1){
            ans *= powl(i, min1);
        }else{
            ans *= powl(i, min2);
        }
    }
    cout << ans << endl;
    return 0;
}

