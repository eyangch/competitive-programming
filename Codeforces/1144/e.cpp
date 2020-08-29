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
    int K; cin >> K;
    string s, t; cin >> s >> t;
    int a[K], b[K], sum[K+1], div[K]; 
    for(int i = 0; i < K; i++){
        a[i] = (int)s[K-i-1] - 'a';
        b[i] = (int)t[K-i-1] - 'a';
    }
    int carry = 0;
    for(int i = 0; i < K; i++){
        int tmpsum = a[i] + b[i] + carry;
        if(tmpsum > 25){
            tmpsum -= 26;
            carry = 1;
        }else{
            carry = 0;
        }
        sum[i] = tmpsum;
    }
    sum[K] = carry;
    int prev = sum[K];
    for(int i = K-1; i >= 0; i--){
        int curr = sum[i] + 26*prev;
        div[i] = curr / 2;
        prev = curr % 2;
    }
    for(int i = K-1; i >= 0; i--){
        cout << (char)(div[i] + 'a');
    }cout << endl;
    return 0;
}


