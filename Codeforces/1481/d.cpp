#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second

using namespace std;
typedef pair<int, int> pii;

int T, N, M;
string s[1000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++){
            cin >> s[i];
        }
        if(M % 2){
            cout << "YES" << endl;
            for(int i = 0; i <= M; i++){
                cout << i % 2 + 1 << " ";
            }
            cout << endl;
        }else{
            int x = -1, y = -1;
            for(int i = 0; i < N; i++){
                for(int j = i+1; j < N; j++){
                    if(s[i][j] == s[j][i]) x = i, y = j;
                }
            }
            if(x > -1){
                cout << "YES" << endl;
                for(int i = 0; i <= M; i++){
                    cout << (i % 2 ? x : y) + 1 << " ";
                }
                cout << endl;
            }else{
                if(N < 3){
                    cout << "NO" << endl;
                }else{
                    int a = -1, b = -1, c = -1;
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            for(int k = 0; k < 3; k++){
                                if(k == j || k == i || j == i) continue;
                                if(s[i][j] == s[j][k]){
                                    a = i, b = j, c = k;
                                }
                            }
                        }
                    }
                    cout << "YES" << endl;
                    if(M % 4){
                        for(int i = 0; i <= M; i++){
                            cout << (i % 2 ? b : (i % 4 ? c : a)) + 1 << " ";
                        }
                    }else{
                        for(int i = 0; i <= M; i++){
                            cout << (i % 2 ? (i % 4 == 1 ? c : a) : b) + 1 << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }
    }
}
