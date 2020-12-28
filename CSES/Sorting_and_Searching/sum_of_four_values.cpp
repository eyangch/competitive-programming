#include <bits/stdc++.h>

using namespace std;

int N, x;
pair<int, int> a[1000];

signed main(){
    cin >> N >> x;
    for(int i = 0; i < N; i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+N);
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int l = j+1, r = N-1;
            while(l < r){
                int v = a[i].first + a[j].first + a[l].first + a[r].first;
                if(v == x){
                    cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second << endl;
                    return 0;
                }else if(v < x){
                    l++;
                }else{
                    r--;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
