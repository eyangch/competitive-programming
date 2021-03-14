#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int N, a[200000];
vector<pair<int, int>> v[5000001];

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> N;
    for(int i = 0; i < N; i++){
        eat >> a[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int sum = a[i] + a[j];
            int cnti = 0, cntj = 0;
            for(pair<int, int> k : v[sum]){
                if(i == k.first || i == k.second){
                    cnti++;
                }else if(j == k.first || j == k.second){
                    cntj++;
                }else{
                    moo << "YeS" << endl << i+1 << " " << j+1 << " " << k.first+1 << " " << k.second+1 << endl;
                    return 0;
                }
            }
            if(cnti < 2 && cntj < 2){
                v[sum].push_back({i, j});
            }
        }
    }
    moo << "nO" << endl;
}
