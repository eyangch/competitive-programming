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
ostream &operator <<(ostream &os, multiset<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

bool works(int N, int (&a)[100000], int mid){
    multiset<int> active;
    int locs[N];
    fill(locs, locs+N, 0);
    for(int i = 0; i < N; i++){
        locs[a[i]-1]++;
    }
    for(int i = 0; i < N; i++){
        if(locs[i] != 0){
            active.insert(locs[i]);
        }
    }
    int stat[N];
    for(int i = 0; i < N; i++){
        if((int)active.size() == 0){
            return false;
        }
        auto it = active.end();
        it--;
        stat[i] = *it;
        active.erase(it);
        if(i >= mid && stat[i-mid]-1 > 0){
            active.insert(stat[i-mid]-1);
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int N; cin >> N;
        int a[100000];
        for(int i = 0; i < N; i++){
            cin >> a[i];
        }   
        int lo = 0;
        int hi = 100005;
        int mid = 0;
        while(lo < hi){
            mid = (lo+hi)/2;
            bool ok = works(N, a, mid);
            if(ok){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        while(works(N, a, mid)){
            mid++;
        }
        while(!works(N, a, mid)){
            mid--;
        }
        cout << mid << endl;
    }
    return 0;
}


