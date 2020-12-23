#include <bits/stdc++.h>
#define int long long

using namespace std;

int N;
int f[100000];

bool cmp(int id1, int id2){
    return (10 * f[id1]) < (9 * f[id2]);
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> f[i];
    }
    sort(f, f+N);
    int ans = 0;
    int ptr = 0;
    for(int i = 0; i < N; i++){
        while(cmp(ptr, i)){
            ptr++;   
        }
        ans += i-ptr;
    }
    cout << ans << endl;
}
