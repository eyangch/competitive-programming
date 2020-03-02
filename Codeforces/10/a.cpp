#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, p1, p2, p3, t1, t2, power = 0;
    cin >> N >> p1 >> p2 >> p3 >> t1 >> t2;
    int l[N], r[N];
    for(int i = 0; i < N; i++){
        cin >> l[i] >> r[i];
    }
    power += p1 * (r[0] - l[0]);
    int currenttime = r[0];
    for(int i = 1; i < N; i++){
        power += p1 * min(l[i] - currenttime, t1);
        power += p2 * min(max(l[i] - currenttime - t1, 0), t2);
        power += p3 * max(l[i] - currenttime - t1 - t2, 0);
        power += p1 * (r[i] - l[i]);
        currenttime = r[i];
    }
    cout << power << endl;
    return 0;
}
