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

bool works(int a[100000], int pfx){
    int order[pfx];
    copy(a, a+pfx, order);
    sort(order, order+pfx);
    int mins[pfx], maxs[pfx];
    fill(mins, mins+pfx, INT_MAX);
    fill(maxs, maxs+pfx, 0);
    set<int> plates[pfx];
    int sPtr = 0;
    int pPtr = 0;
    for(int i = 0; i < pfx; i++){
        int stackidx = upper_bound(mins+pPtr, mins+pfx, a[i]) - mins;
        if(stackidx > pPtr){
            if(a[i] < maxs[stackidx-1]){
                return false;
            }
        }
        mins[stackidx] = a[i];
        plates[stackidx].insert(a[i]);
        if(maxs[stackidx] == 0) maxs[stackidx] = a[i];
        while(pPtr < pfx && sPtr < pfx && mins[pPtr] == order[sPtr]){
            plates[pPtr].erase(order[sPtr]);
            if((int)plates[pPtr].size() == 0){
                pPtr++;
            }else{
                mins[pPtr] = *plates[pPtr].begin();
            }
            sPtr++;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    int N; cin >> N;
    int a[100000];
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    int lo = 1;
    int hi = N;
    int mid = (lo+hi)/2;
    while(lo < hi){
        mid = (lo+hi)/2;
        if(works(a, mid)){
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    while(works(a, mid)) mid++;
    while(!works(a, mid)) mid--;
    cout << mid << endl;
    return 0;
}


