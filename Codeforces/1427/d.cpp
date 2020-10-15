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

int N;
int c[52];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> c[i];
    }
    vector<vi> ops;
    bool x = N % 2;
    for(int i = 0; i < N-1; i++){
        if(!x){
            x = !x;
            if(i == 0 && c[i] == 1){
                continue;
            }
            vi op;
            vector<pii> op2;
            int end;
            for(end = 0; end < N; end++){
                if(c[end] == i+1){
                    break;
                }
            }
            if(end > 0){
                op.push_back(end);
                op2.push_back(pii(0, end));
            }
            if(N - i - end > 0){
                op.push_back(N-i-end);
                op2.push_back(pii(end, N-i));
            }
            for(int j = 0; j < i; j++){
                op.push_back(1);
                op2.push_back(pii(N-i+j, N-i+j+1));
            }
            //cout << op2 << endl; 
            int curr[52];
            int cnt = 0;
            for(int j = (int)op2.size()-1; j >= 0; j--){
                for(int k = op2[j].f; k < op2[j].s; k++){
                    curr[cnt] = c[k];
                    cnt++;
                }
            }
            copy(curr, curr+N, c);
            ops.push_back(op);
        }else{
            x = !x;
            if(i == 0 && c[N-1-i] == 1){
                continue;
            }
            vi op;
            vector<pii> op2;
            for(int j = 0; j < i; j++){
                op.push_back(1);
                op2.push_back(pii(j, j+1));
            }
            int end;
            for(end = 0; end < N; end++){
                if(c[end] == i+1){
                    break;
                }
            }
            if(end+1-i > 0){
                op.push_back(end+1-i);
                op2.push_back(pii(i, end+1));
            }
            if(N - (end+1) > 0){
                op.push_back(N-(end+1));
                op2.push_back(pii(end+1, N));
            }
            //cout << op2 << endl; 
            int curr[52];
            int cnt = 0;
            for(int j = (int)op2.size()-1; j >= 0; j--){
                for(int k = op2[j].f; k < op2[j].s; k++){
                    curr[cnt] = c[k];
                    cnt++;
                }
            }
            copy(curr, curr+N, c);
            ops.push_back(op);
        }
        /*for(int j = 0; j < N; j++){
            cout << c[j] << " ";
        }cout << endl;*/
    }
    cout << ops.size() << endl;
    for(vi x : ops){
        cout << x.size() << " ";
        for(int i : x){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}


