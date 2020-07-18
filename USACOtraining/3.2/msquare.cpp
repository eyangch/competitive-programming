/*
ID: sireric1
LANG: C++11
TASK: msquare
*/

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

int efact = 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;

void A(vi &a){
    reverse(a.begin(), a.end());
}

void rA(vi &a){
    A(a);
}

void B(vi &a){
    swap(a[0], a[3]);
    swap(a[4], a[7]);
    swap(a[3], a[2]);
    swap(a[4], a[5]);
    swap(a[2], a[1]);
    swap(a[6], a[5]);
}

void rB(vi &a){
    B(a);
    B(a);
    B(a);
}

void C(vi &a){
    swap(a[1], a[2]);
    swap(a[1], a[5]);
    swap(a[1], a[6]);
}

void rC(vi &a){
    C(a);
    C(a);
    C(a);
}

int ahash(vi &a){
    int ret = 0;
    int mul = efact;
    bool alrdy[8];
    fill(alrdy, alrdy+8, false);
    for(int i = 8; i > 0; i--){
        mul /= i;
        int idx = 8-i;
        int val = a[idx]-1;
        int sub = 0;
        for(int j = 0; j < val; j++) sub += alrdy[j];
        ret += (val-sub) * mul;
        alrdy[val] = true;
    }
    return ret;
}

vi rhash(int h){
    vi ret;
    int div = efact;
    bool alrdy[8];
    fill(alrdy, alrdy+8, false);
    for(int i = 8; i > 0; i--){
        div /= i;
        int tval = h / div;
        h %= div;
        int pv[8];
        pv[0] = alrdy[0];
        for(int j = 1; j < 8; j++){
            pv[j] = pv[j-1] + alrdy[j];
        }
        for(int j = tval; j < 8; j++){
            if(tval + pv[j] == j){
                tval = j;
                break;
            }
        }
        ret.push_back(tval+1);
        alrdy[tval] = true;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    vi a(8);
    for(int i = 0; i < 8; i++){
        cin >> a[i];
    }
    int dist[efact+1];
    fill(dist, dist+efact+1, INT_MAX);
    queue<pii> bfs;
    bfs.push(pii(ahash(a), 0));
    while(!bfs.empty()){
        int hs = bfs.front().first, distc = bfs.front().second;
        bfs.pop();
        if(dist[hs] != INT_MAX){
            continue;
        }
        dist[hs] = distc;
        if(hs == 0){
            break;
        }
        vi carr = rhash(hs);
        rA(carr);
        int tA = ahash(carr);
        A(carr);
        rB(carr);
        int tB = ahash(carr);
        B(carr);
        rC(carr);
        int tC = ahash(carr);
        bfs.push(pii(tA, distc+1));
        bfs.push(pii(tB, distc+1));
        bfs.push(pii(tC, distc+1));
    }
    int hidx = 0;
    string ans;
    while(dist[hidx] != 0){
        vi carr = rhash(hidx);
        int minDist = INT_MAX;
        int midx = 0;
        char ltr = 'A';
        A(carr);
        int tA = ahash(carr);
        rA(carr);
        B(carr);
        int tB = ahash(carr);
        rB(carr);
        C(carr);
        int tC = ahash(carr);
        if(dist[tA] < minDist){
            minDist = dist[tA];
            midx = tA;
            ltr = 'A';
        }
        if(dist[tB] < minDist){
            minDist = dist[tB];
            midx = tB;
            ltr = 'B';
        }
        if(dist[tC] < minDist){
            minDist = dist[tC];
            midx = tC;
            ltr = 'C';
        }
        ans += ltr;
        hidx = midx;
    }
    vi orig = rhash(hidx);
    cout << ans.length() << endl << ans << endl;
    return 0;
}


