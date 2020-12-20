#include <bits/stdc++.h>

using namespace std;

int N, K, R;
int dna[200000];
int req[200000], cur[200000];
int rch = 0;

signed main(){
    cin >> N >> K >> R;
    for(int i = 0; i < N; i++){
        cin >> dna[i];
    }
    for(int i = 0; i < R; i++){
        int a, b; cin >> a >> b;
        req[a] = b;
        rch++;
    }
    int ans = 1e7;
    int end = 0;
    for(int i = 0; i < N; i++){
        while(end < N && rch > 0){
            if(++cur[dna[end]] == req[dna[end]]){
                rch--;
            }
            end++;
        }
        if(rch == 0){
            ans = min(ans, end - i);
        }
        if(cur[dna[i]]-- == req[dna[i]]){
            rch++;
        }
    }
    cout << (ans == 1e7 ? "impossible" : to_string(ans)) << endl;
}
