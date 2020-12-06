#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

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

map<char, int> q;

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    int ans =0;
    int cnt = 0;
    while(getline(cin, nxt)){
        if(nxt == ""){
            for(auto it = q.begin(); it != q.end(); it++){
                if(it -> second == cnt){
                    ans++;
                }
            }
            q.clear();
            cnt = 0;
        }else{
            for(char i : nxt){
                q[i]++;
            }
            cnt++;
        }
    }
    for(auto it = q.begin(); it != q.end(); it++){
                if(it -> second == cnt){
                    ans++;
                }
            }
    cout << ans << endl;
    return 0;
}




