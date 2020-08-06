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

int get(int x, int (&BIT)[100001]){
    int sum = 0;
    for(; x > 0; x -= x&-x){
        sum += BIT[x];
    }
    return sum;
}

void upd(int x, int dv, int N, int (&BIT)[100001]){
    for(; x <= N; x += x&-x){
        BIT[x] += dv;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    int N; cin >> N;
    pii h[N];
    int BIT[100001];
    fill(BIT, BIT+N, 0);
    for(int i = 0; i < N; i++){
        cin >> h[i].first;
        h[i].second = i+1;   
    }
    sort(h, h+N);
    int ans = 0;
    for(int i = N-1; i >= 0; i--){
        int left = get(h[i].second, BIT);
        int right = (N-1-i) - left;
        if(min(left, right) * 2 < max(left, right)){
            ans++;
        }
        upd(h[i].second, 1, N, BIT);
    }
    cout << ans << endl;
    return 0;
}


