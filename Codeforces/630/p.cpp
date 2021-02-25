#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const double pi = 3.14159265358979323846;
double N, R;

int32_t main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N >> R;
    double x = pi / 2 - pi / N;
    double s = 2 * R * cos(x);
    double y = x - pi / 2 / N;
    double ans = N * 0.5 * s * (R * sin(x) - s * tan(y) / 2);
    cout << setprecision(9) << ans << endl;
}
