#include <bits/stdc++.h>
#define f first
#define s second
//#define endl "\n"
#define int __int128

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

ll T;
int MOD = 1;

int fexp(int a, ll b){
    int ans = 1;
    for(int i = 0; i < 63; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    cin >> T;
    cin >> nxt;
    int bef = 0;
    int currn = -1;
    vector<pii> nums;
    for(int i = 0; i <= (int)nxt.size(); i++){
        if(i == (int)nxt.size() || nxt[i] == ','){
            string strnum = nxt.substr(bef, i-bef); 
            bef = i+1;
            currn++;
            if(strnum == "x"){
                continue;
            }
            int num = stoi(strnum);
            nums.push_back(pii(num, (num - currn % num) % num));
            MOD *= num;
        }
    }
    cout << (ll)MOD << endl;
    int ans = 0;
    for(pii i : nums){
        int b = MOD / i.f;
        int binv = fexp(b, i.f-2);
        ans = (ans + i.s * b % MOD * binv % MOD) % MOD;
    }
    cout << (long long)ans << endl;
    return 0;
}




