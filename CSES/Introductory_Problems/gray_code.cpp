#include <bits/stdc++.h>

using namespace std;

int N;
bool vis[1<<17];

int32_t main(){
    cin >> N;
    int x = 0;
    for(int i = 0; i < (1<<N); i++){
        cout << bitset<16>(x).to_string().substr(16-N) << endl;
        vis[x] = true;
        for(int j = 0; j < N; j++){
            if(vis[x ^ (1<<j)]) continue;
            x ^= (1<<j);
            break;
        }
    }
}
