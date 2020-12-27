#include <bits/stdc++.h>

using namespace std;

int X, N;
multiset<int> l, segs;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X >> N;
    segs.insert(X);
    l.insert(0);
    l.insert(X);
    for(int i = 0; i < N; i++){
        int p; cin >> p;
        auto it = l.upper_bound(p);
        int after = *it;
        int before = *(--it);
        segs.erase(segs.find(after-before));
        segs.insert(after-p);
        segs.insert(p-before);
        cout << *segs.rbegin() << " ";
        l.insert(p);
    }
    cout << endl;
}
