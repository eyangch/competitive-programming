/*
ID: sireric1
LANG: C++11
TASK: job
*/

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

int N, M1, M2;
int a[30], b[30];
int aq[30], bq[30];
int ao[1000];

int main(){
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cin >> N >> M1 >> M2;
    for(int i = 0; i < M1; i++){
        int x; cin >> x;
        a[i] = x;
        aq[i] = x;
    }
    for(int i = 0; i < M2; i++){
        int x; cin >> x;
        b[i] = x;
        bq[i] = x;
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < N; i++){
        int mt = INT_MAX, mid = 0;
        for(int j = 0; j < M1; j++){
            if(aq[j] < mt){
                mt = aq[j];
                mid = j;
            }
        }
        aq[mid] += a[mid];
        ans1 = mt;
        ao[i] = mt;
    }
    for(int i = N-1; i >= 0; i--){
        int mt = INT_MAX, mid = 0;
        for(int j = 0; j < M2; j++){
            if(ao[i] + bq[j] < mt){
                mt = ao[i] + bq[j];
                mid = j;
            }
        }
        bq[mid] += b[mid];
        ans2 = max(ans2, mt);
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}


