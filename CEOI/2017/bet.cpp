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
double a[100000], b[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
    }
    sort(a, a+N, greater<double>());
    sort(b, b+N, greater<double>());
    for(int i = 1; i < N; i++){
        a[i] += a[i-1];
        b[i] += b[i-1];
    }
    double ans = 0;
    for(int i = 0; i < N; i++){
        int lo = 0, hi = N-1;
        int mid = 0;
        while(lo < hi){
            mid = (lo+hi)/2;
            double scorea = a[i] - mid - i-2, scoreb = b[mid] - mid - i-2;
            if(scoreb < scorea){
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        while(mid > 0 && b[mid] - mid - i-2 >  a[i] - mid - i-2){
            mid--;
        }
        while(mid < N-1 && b[mid] - mid - i-2 <  a[i] - mid - i-2){
            mid++;
        }
        ans = max(ans, min(a[i] - mid - i-2, b[mid] - mid - i-2));
        mid--;
        if(mid >= 0){
            ans = max(ans, min(a[i] - mid - i-2, b[mid] - mid - i-2));
        }
    }
    cout << fixed << setprecision(4) << ans << endl;
    return 0;
}


