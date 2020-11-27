#include <bits/stdc++.h>
#define f first
#define s second

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

string cb[8];
int ans = 0;

void dfs(int x, int y, int ph, int pd1, int pd2){
    int vph = (1<<x), vpd1 = (1<<(x+y)), vpd2 = (1<<(x-y+7));
    if(vph&ph || vpd1&pd1 || vpd2&pd2 || cb[x][y] == '*'){
        return;
    }
    ph |= vph;
    pd1 |= vpd1;
    pd2 |= vpd2;
    if(y == 7){
        ans++;
    }else{        
        for(int i = 0; i < 8; i++){
            dfs(i, y+1, ph, pd1, pd2);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 8; i++){
        cin >> cb[i];   
    }
    for(int i = 0; i < 8; i++){
        dfs(i, 0, 0, 0, 0);
    }
    cout << ans << endl;
    return 0;
}


