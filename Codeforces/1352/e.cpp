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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        int cnt[n+1];
        fill(cnt, cnt + n + 1, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];   
            cnt[a[i]]++;
        }
        int pfx[n];
        pfx[0] = a[0];
        int ans = 0;
        bool done[n+1];
        fill(done, done + n + 1, false);
        for(int i = 1; i < n; i++){
            pfx[i] = pfx[i-1] + a[i];
            if(pfx[i] <= n && !done[pfx[i]]){
                ans += cnt[pfx[i]];
                done[pfx[i]] = true;
            }
        }
        for(int i = 0; i < n-2; i++){
            for(int j = i + 2; j < n; j++){
                if(pfx[j] - pfx[i] > n){
                    break;
                }
                if(!done[pfx[j] - pfx[i]]){
                    ans += cnt[pfx[j] - pfx[i]];
                    done[pfx[j] - pfx[i]] = true;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}


