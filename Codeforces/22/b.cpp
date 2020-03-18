#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("cin", "r", stdin);
    int N, M; cin >> N >> M;
    string r[N];
    int ans = 0;
    for(int i = 0; i < N; i++) cin >> r[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(r[i][j] == '1'){
                continue;
            }
            for(int k = i; k < N; k++){
                for(int l = j; l < M; l++){
                    if(r[k][l] == '1'){
                        continue;
                    }
                    bool good = true;
                    for(int x = i; x < k + 1; x++){
                        for(int y = j; y < l + 1; y++){
                            if(r[x][y] == '1'){
                                good = false;
                                break;
                            }
                        }
                        if(!good){
                            break;
                        }
                    }
                    if(!good){
                        break;
                    }else{
                        ans = max(ans, 2 * ((k - i + 1) + (l - j + 1)));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
