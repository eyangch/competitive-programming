#include <bits/stdc++.h>
#include "grader.h"
#include "cluedo.h"
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

void Solve(){
    int a = 1, b = 1, c = 1;
    while(true){
        int x = Theory(a, b, c);
        if(x == 0){
            return;
        }else if(x == 1){
            a++;
        }else if(x == 2){
            b++;
        }else{
            c++;
        }
    }
}

/*int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    return 0;
}*/


