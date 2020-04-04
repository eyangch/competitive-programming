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
    int n; cin >> n;
    vector<vi> all;
    for(int i = 1; i < n+2; i++){
        vi curr;
        for(int j = 0; j < i; j++){
            curr.push_back(j);
        }
        for(int j = i-2; j >= 0; j--){
            curr.push_back(j);
        }
        for(int j = 0; j < (n - (i - 1)) * 2; j++){
            cout << " ";   
        }
        for(int j = 0; j < (int)curr.size(); j++){
            cout << curr[j];
            if(j != (int)curr.size()-1){
                cout << " ";
            }
        }
        cout << endl;
    }
    for(int i = n; i >= 1; i--){
        vi curr;
        for(int j = 0; j < i; j++){
            curr.push_back(j);
        }
        for(int j = i-2; j >= 0; j--){
            curr.push_back(j);
        }
        for(int j = 0; j < (n - (i - 1)) * 2; j++){
            cout << " ";   
        }
        for(int j = 0; j < (int)curr.size(); j++){
            cout << curr[j];
            if(j != (int)curr.size()-1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}


