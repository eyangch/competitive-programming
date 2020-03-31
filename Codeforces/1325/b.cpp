#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        int N;
        set<int> a;
        cin >> N;
        for(int i = 0; i < N; i++){
            int x; cin >> x; a.insert(x);
        }
        cout << a.size() << endl;
    }
    return 0;
}
