#include <bits/stdc++.h>
#define int long long

using namespace std;

int N;

int qry(int l, int r){
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int ret; cin >> ret;
    return ret;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int id1 = qry(1, N);
    if(id1 != 1 && qry(1, id1) == id1){
        int lo = 1, hi = id1-1, mid = 0, fm = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            int x = qry(mid, id1);
            if(x == id1) lo = mid+1, fm = mid;
            else hi = mid-1;
        }
        cout << "! " << fm << endl;
    }else{
        int lo = id1+1, hi = N, mid = 0, fm = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            int x = qry(id1, mid);
            if(x == id1) hi = mid-1, fm = mid;
            else lo = mid+1;
        }
        cout << "! " << fm << endl;
    }
}
