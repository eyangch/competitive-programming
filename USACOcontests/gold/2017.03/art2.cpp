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
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    int N; cin >> N;
    int a[N+1];
    int bl[N+1];
    int last[N+1];
    fill(bl, bl+N+1, -1);
    stack<int> colors;
    colors.push(0);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        last[a[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(a[i] == 0){
            if(colors.size() > 1){
                cout << -1 << endl;
                return 0;
            }
        }else{
            if(bl[a[i]] == -1){
                bl[a[i]] = colors.top();
                colors.push(a[i]);
            }
            ans = max(ans, (int)colors.size()-1);
            if(last[a[i]] == i){
                colors.pop();
                if(colors.top() != bl[a[i]]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


