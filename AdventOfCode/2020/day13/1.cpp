#include <bits/stdc++.h>
#define f first
#define s second
//#define endl "\n"
#define int ll

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

int T;

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    cin >> T;
    cin >> nxt;
    int bef = 0;
    int mnwait = 1e9;
    int ans = 0;
    for(int i = 0; i <= (int)nxt.size(); i++){
        if(i == (int)nxt.size() || nxt[i] == ','){
            string strnum = nxt.substr(bef, i-bef); 
            bef = i+1;
            if(strnum == "x"){
                continue;
            }
            int num = stoi(strnum);
            int score = num - (T % num) % num;
            if(score < mnwait){
                mnwait = score;
                ans = score * num;
            }
        }
    }
    cout << ans << endl;
    return 0;
}



