#include <bits/stdc++.h>
#define f first
#define s second
//#define endl "\n"
#define int ll

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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int x, y;
void mv(int id, int amt){
    x += dx[id] * amt;
    y += dy[id] * amt;
}

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    int ori = 1;
    while(cin >> nxt){
        int amt = stoi(nxt.substr(1));
        switch(nxt[0]){
            case 'L':
                ori = (ori - amt/90 + 4) % 4;
                break;
            case 'R':
                ori = (ori + amt/90) % 4;
                break;
            case 'F':
                mv(ori, amt);
                break;
            case 'N':
                mv(0, amt);
                break;
            case 'E':
                mv(1, amt);
                break;
            case 'S':
                mv(2, amt);
                break;
            case 'W':
                mv(3, amt);
                break;
        }
    }
    cout << abs(x) + abs(y) << endl;
    return 0;
}



