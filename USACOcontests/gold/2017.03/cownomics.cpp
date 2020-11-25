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

int N, M;
string a[500], b[500];
unordered_set<string> spot;

bool works(int beg, int end){
    spot.clear();
    //cout << beg << " " << end << " " << a[0].substr(beg, end - beg) << endl;
    for(int i = 0; i < N; i++){
        spot.insert(a[i].substr(beg, end - beg));
    }
    for(int i = 0; i < N; i++){
        if(spot.find(b[i].substr(beg, end - beg)) != spot.end()){
            return false;
        }
    }
    return true;
}

signed main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    int beg = 0, end = 1;
    int ans = INT_MAX;
    while(end <= M){
        if(works(beg, end)){
            while(beg < end){
                if(!works(beg+1, end)){
                    ans = min(ans, end-beg);
                    beg++;
                    break;
                }
                beg++;
            }
        }
        end++;
    }
    cout << ans << endl;
    return 0;
}


