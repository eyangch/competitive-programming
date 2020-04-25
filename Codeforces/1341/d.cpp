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

const string d0 = "1110111";
const string d1 = "0010010";
const string d2 = "1011101";
const string d3 = "1011011";
const string d4 = "0111010";
const string d5 = "1101011";
const string d6 = "1101111";
const string d7 = "1010010";
const string d8 = "1111111";
const string d9 = "1111011";

string d[10] = {d0, d1, d2, d3, d4, d5, d6, d7, d8, d9};

int s2i(string x){
    int ret = 0;
    for(; d[ret] != x; ret++){}
    return ret;   
}

int main(){
    int n, kg; cin >> n >> kg;
    string a[n];
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        a[i] = s;
    }
    int gt[n][10];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            int x = 0;
            for(int k = 0; k < 7; k++){
                if(a[i][k] == '1' && d[j][k] == '0'){
                    x = -1;
                    break;
                }else if(a[i][k] == '0' && d[j][k] == '1'){
                    x++;
                }
            }
            gt[i][j] = x;
            //cout << gt[i][j] << " ";
        }//cout << endl;
    }
    int dp[n + 1][kg + 1];
    fill(dp[0], dp[n] + kg + 1, false);
    dp[n][0] = true;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= kg; j++){
            if(!dp[i][j]){
                continue;
            }
            for(int k = 0; k < 10; k++){
                int val = gt[i-1][k];
                if(val != -1 && j + val <= kg){
                    dp[i-1][j + val] = true;
                }
            }
        }
    }
    if(!dp[0][kg]){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        int ans = -1;
        int val = i;
        for(int j = 0; j < 10; j++){
            if(gt[val][j] <= kg && gt[val][j] != -1 && dp[i + 1][kg - gt[val][j]]){
                ans = j;
            }
        }
        kg -= gt[val][ans];
        cout << ans;
    }
    cout << endl;
    return 0;
}


