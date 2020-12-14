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

int dx = 10;
int dy = -1;

int x, y;
void mv(int amt){
    x += dx * amt;
    y += dy * amt;
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
            case 'R':
                for(int i = 0; i < amt; i += 90){
                    swap(dx, dy);
                    dx = -dx;
                }
                break;
            case 'L':
                for(int i = 0; i < amt; i += 90){
                    swap(dx, dy);
                    dy = -dy;
                }
                break;
            case 'F':
                mv(amt);
                break;
            case 'N':
                dy -= amt;
                break;
            case 'E':
                dx += amt;
                break;
            case 'S':
                dy += amt;
                break;
            case 'W':
                dx -= amt;
                break;
        }
    }
    cout << abs(x) + abs(y) << endl;
    return 0;
}



