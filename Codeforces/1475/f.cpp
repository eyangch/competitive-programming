#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N;
bitset<1000> a[1000], b[1000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            a[i].reset();
            string s; cin >> s;
            for(int j = 0; j < N; j++){
                a[i][j] = (s[j] == '1');
            }
        }
        for(int i = 0; i < N; i++){
            b[i].reset();
            string s; cin >> s;
            for(int j = 0; j < N; j++){
                b[i][j] = (s[j] == '1');
            }
        }
        for(int i = 0; i < N; i++){
            if(a[i][0] != b[i][0]){
                for(int j = 0; j < N; j++){
                    a[i].flip(j);
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(a[0][i] != b[0][i]){
                for(int j = 0; j < N; j++){
                    a[j].flip(i);
                }
            }
        }
        bool good = true;
        for(int i = 0; i < N; i++){
            good &= (a[i] == b[i]);
        }
        cout << (good ? "YES" : "NO") << endl;
    }
}
