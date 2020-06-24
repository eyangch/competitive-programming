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

int N, K;
int a[200000];

bool works(int x){
    int odd = 0;
    bool b = false;
    for(int i = 0; i < N; i++){
        if(b){
            odd++;
            b = false;
        }else if(a[i] <= x){
            odd++;
            b = true;
        }
    }
    int even = 0;
    b = true;
    for(int i = 0; i < N; i++){
        if(b){
            even++;
            b = false;
        }else if(a[i] <= x){
            even++;
            b = true;
        }
    }
    return (odd >= K || even >= K);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];   
    }
    int asort[N];
    copy(a, a+N, asort);
    sort(asort, asort+N);
    int lo = 0;
    int hi = N-1;
    int mid;
    while(lo < hi){
        mid = lo + (hi-lo)/2;
        bool ok = works(asort[mid]);
        if(ok){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    while(mid > 0 && works(asort[mid])){
        mid--;
    }
    while(!works(asort[mid])){
        mid++;
    }
    cout << asort[mid] << endl;
    return 0;
}


