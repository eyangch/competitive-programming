#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"
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

int p_sz = 25;

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    int nxt;
    int ans =0;
    multiset<int> pv;
    vi a;
    int N = 0;
    int bad = 0;
    while(cin >> nxt){
        if(N >= p_sz){
            bool good = false;
            for(auto it = pv.begin(); it != pv.end(); it++){
                auto it2 = pv.lower_bound(nxt - *it);
                if(it != it2 && it2 != pv.end() && *it + *it2 == nxt){
                    good = true;
                    break;
                }
            }
            if(!good){
                cout << nxt << endl;
                bad = nxt;
            }
            pv.erase(pv.find(a[N-p_sz]));
        }
        pv.insert(nxt);
        a.push_back(nxt);
        N++;
    }
    int beg = 0, end = 0;
    int sum = 0;
    while(beg < N && end < N){
        while(end < N-1 && sum + a[end] <= bad){
            sum += a[end++];
        }
        if(sum == bad && end - beg >= 2){
            int mn = 1e9, mx = 0;
            for(int i = beg; i < end; i++){
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
            cout << mn + mx << endl;
        }
        sum -= a[beg++];
    }
    return 0;
}



