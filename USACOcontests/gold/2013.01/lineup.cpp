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

int N, K;
int b[100000];

signed main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    int ans = 0;
    int beg = 0, end = 0;
    map<int, int> cnt;
    set<pii> occ;
    while(end < N){
        if(cnt.find(b[end]) == cnt.end()){
            cnt[b[end]] = 1;
            occ.insert(pii(1, b[end]));
        }else{
            occ.erase(pii(cnt[b[end]], b[end]));
            cnt[b[end]]++;
            occ.insert(pii(cnt[b[end]], b[end]));
        }
        while((int)cnt.size() > K+1){
            occ.erase(pii(cnt[b[beg]], b[beg]));
            cnt[b[beg]]--;
            if(cnt[b[beg]] > 0){
                occ.insert(pii(cnt[b[beg]], b[beg]));
            }else{
                cnt.erase(b[beg]);
            }
            beg++;
        }
        int maxocc = (*(occ.rbegin())).f;
        ans = max(ans, maxocc);
        end++;
    }
    cout << ans << endl;
    return 0;
}


