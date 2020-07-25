/*
ID: sireric1
LANG: C++11
TASK: shopping
*/
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

struct offer{
    vector<pii> products;
    int price;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    int S; cin >> S;
    offer ofs[110];
    for(int i = 0; i < S; i++){
        int N; cin >> N;
        for(int j = 0; j < N; j++){
            int a, b; cin >> a >> b;
            ofs[i].products.push_back(pii(a, b));
        }
        cin >> ofs[i].price;
    }
    int B; cin >> B;
    int fwd[5], bck[1000];
    int limit[5], rprice[5];
    fill(limit, limit+5, 0);
    for(int i = 0; i < B; i++){
        int c, k, p; cin >> c >> k >> p;
        fwd[i] = c;
        bck[c] = i;
        limit[i] = k;
        ofs[S+i].products.push_back(pii(c, 1));
        ofs[S+i].price = p;
    }
    int dp[6][6][6][6][6];
    fill(dp[0][0][0][0], dp[5][5][5][5]+6, INT_MAX);
    dp[0][0][0][0][0] = 0;
    for(int i = 0; i <= limit[0]; i++){
        for(int j = 0; j <= limit[1]; j++){
            for(int k = 0; k <= limit[2]; k++){
                for(int l = 0; l <= limit[3]; l++){
                    for(int m = 0; m <= limit[4]; m++){
                        for(int n = 0; n < S+B; n++){
                            int a[5];
                            a[0] = i; a[1] = j; a[2] = k; a[3] = l; a[4] = m;
                            for(pii off : ofs[n].products){
                                a[bck[off.first]] += off.second;
                            }
                            bool good = true;
                            for(int o = 0; o < 5; o++){
                                if(a[o] > limit[o]){
                                    good = false;
                                    break;
                                }
                            }
                            if(!good){
                                continue;
                            }
                            dp[a[0]][a[1]][a[2]][a[3]][a[4]] = min(dp[a[0]][a[1]][a[2]][a[3]][a[4]], dp[i][j][k][l][m] + ofs[n].price);
                        }
                    }
                }
            }
        }
    }
    cout << dp[limit[0]][limit[1]][limit[2]][limit[3]][limit[4]] << endl;
    return 0;
}


