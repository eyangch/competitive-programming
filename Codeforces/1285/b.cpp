#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int T;
    ofstream fout("b.out");
    cin >> T;
    for(int testcase = 0; testcase < T; testcase++){
        ll N, c[100000], total = 0, tmax = INT_MIN, current;
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> c[i];
            total += c[i];
            tmax = max(c[i], tmax);
        }
        for(int add = 0; add < 2; add++){
            current = 0;
            for(int i = 0 + add; i < N - 1 + add; i++){
                if(current + c[i] > 0){
                    current += c[i];
                    tmax = max(current, tmax);
                }else{
                    current = 0;
                }
            }
        }
        if(total > tmax){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
