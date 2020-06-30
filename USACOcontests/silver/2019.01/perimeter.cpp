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

void calc(int &n, string (&s)[1000], int &p, int &a, bool (&v)[1000][1000], int x, int y){
    if(x < 0 || y < 0 || x > n - 1 || y > n - 1 || v[x][y] || s[x][y] == '.'){
        return;
    }
    v[x][y] = true;
    a++;
    if(x == 0 || s[x-1][y] == '.'){
        p++;
    }if(x == n - 1 || s[x+1][y] == '.'){
        p++;
    }if(y == 0 || s[x][y-1] == '.'){
        p++;
    }if(y == n - 1 || s[x][y+1] == '.'){
        p++;
    }
    calc(n, s, p, a, v, x+1, y);
    calc(n, s, p, a, v, x-1, y);
    calc(n, s, p, a, v, x, y+1);
    calc(n, s, p, a, v, x, y-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int n; cin >> n;
    string s[1000];
    for(int i = 0; i < n; i++){
        cin >> s[i];   
    }
    bool visited[1000][1000];
    fill(visited[0], visited[999] + 1000, false);
    int ans_area = 0;
    int ans_perim = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]){
                continue;
            }
            int p = 0, a = 0;
            calc(n, s, p, a, visited, i, j);
            if(a > ans_area || (a == ans_area && p < ans_perim)){
                ans_area = a;
                ans_perim = p;
            }
        }
    }
    cout << ans_area << " " << ans_perim << endl;
    return 0;
}


