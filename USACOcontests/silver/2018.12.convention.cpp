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

bool works(int &n, int m, int &c, int (&cows)[100000], int x){
    int scow = cows[0];
    int sidx = 0;
    for(int i = 1; i < n; i++){
        if(i - sidx >= c || cows[i] - scow > x){
            scow = cows[i];
            sidx = i;
            m--;
        }
        if(m <= 0){
            return false;
        }
    }
    return true;  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c; cin >> n >> m >> c;
    int cows[100000];
    for(int i = 0; i < n; i++){
        cin >> cows[i];   
    }
    sort(cows, cows + n);
    int low = 0;
    int high = 1000000000;
    int mid = (low + high) / 2;
    while(low < high){
        mid = (low + high) / 2;
        bool wk = works(n, m, c, cows, mid);
        bool wk1 = works(n, m, c, cows, mid - 1);
        if(wk && !wk1){
            break;
        }else if(wk){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    while(works(n, m, c, cows, mid)){
        mid--;
    }
    while(!works(n, m, c, cows, mid)){
        mid++;
    }
    cout << mid << endl;
    return 0;
}


