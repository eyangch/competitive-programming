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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    int a[n];
    unordered_set<int> contains;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        contains.insert(a[i]);
    }
    vi jump;
    jump.push_back(a[0]);
    vi cidx;
    cidx.push_back(0);
    for(int i = 0; i < n-1; i++){
        if(a[i] != a[i+1]){
            jump.push_back(a[i+1]);
            cidx.push_back(i+1);
        }
    }
    int filler = 1;
    int maxn = 0;
    int ans[n];
    for(int i = 0; i < n; i++){
        if(a[i] == 0 || (i != 0 && a[i] == a[i-1])){
            while(contains.find(filler) != contains.end()){
                filler++;
            }
            ans[i] = filler;
            maxn = max(maxn, filler);
            filler++;
        }else{
            if((maxn < a[i]-1 && a[i-1] != a[i]-1) || maxn < a[i]-2){
                cout << -1 << endl;
                return 0;
            }
            if(i == 0){
                ans[i] = 0;
            }else{
                maxn = max(maxn, a[i-1]);
                ans[i] = a[i-1];
            }
        }
    }
    for(int i : ans){
        cout << i << " ";
    }cout << endl;
    return 0;
}


