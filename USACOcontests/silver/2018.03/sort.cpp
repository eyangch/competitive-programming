#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int N;
    pair<int, int> arr[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        arr[i].second = i;
        cin >> arr[i].first;
    }
    sort(arr, arr + N);
    int mdist = 0;
    for(int i = 0; i < N; i++){
        mdist = max(mdist, arr[i].second - i);
    }
    cout << mdist + 1 << endl;
    return 0;
}
