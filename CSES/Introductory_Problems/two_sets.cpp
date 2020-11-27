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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    if(N*(N+1)/2 % 2 != 0){
        cout << "NO" << endl;   
    }else{
        cout << "YES" << endl;
        vi a, b;
        int ptr = 1;
        if(N % 2 == 1){
            a.push_back(1);
            a.push_back(2);
            b.push_back(3);
            ptr = 4;
        }
        if(ptr <= N){
            a.push_back(ptr);
            ptr++;
        }
        for(int i = 0; i+ptr <= N; i++){
            if(i / 2 % 2 == 0){
                b.push_back(i+ptr);
            }else{
                a.push_back(i+ptr);
            }
        }
        cout << a.size() << endl;
        for(int i : a){
            cout << i << " ";
        }
        cout << endl;
        cout << b.size() << endl;
        for(int i : b){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}


