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

bool works(int N, int M, int (&expense)[100000], int mid){
    int currmonth = 0;
    int months = 1;
    for(int i = 0; i < N; i++){
        if(currmonth + expense[i] > mid){
            months++;
            currmonth = 0;
        }
        currmonth += expense[i];
        if(currmonth > mid) return false;
    }
    if(months <= M) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    int expense[100000];
    for(int i = 0; i < N; i++){
        cin >> expense[i];   
    }
    int lo = 0;
    int hi = 1000000000;
    int mid = 0;
    while(lo < hi){
        mid = lo + ((hi-lo) / 2);
        bool ok = works(N, M, expense, mid);
        if(ok){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    while(works(N, M, expense, mid)){
        mid--;
    }
    while(!works(N, M, expense, mid)){
        mid++;
    }
    cout << mid << endl;
    return 0;
}
