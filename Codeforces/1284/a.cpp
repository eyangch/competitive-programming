#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M, Q;
    string s[20], t[20];
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    for(int i = 0; i < M; i++){
        cin >> t[i];
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int y;
        cin >> y;
        cout << s[(y-1)%N] << t[(y-1)%M] << endl;
    }
    return 0;
}
