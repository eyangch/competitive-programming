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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];   
        }
        int m = 0, a = 0, b = 0;
        int apt = 0, bpt = n-1;
        int preva = 0, prevb = 0;
        while(apt <= bpt){
            preva = 0;
            while(apt <= bpt && preva <= prevb){
                preva += arr[apt];
                apt++;
            }
            m++;
            a += preva;
            prevb = 0;
            if(apt <= bpt){
                m++;
            }
            while(apt <= bpt && prevb <= preva){
                prevb += arr[bpt];
                bpt--;
            }
            b += prevb;
        }
        cout << m << " " << a << " " << b << endl;
    }
    return 0;
}


