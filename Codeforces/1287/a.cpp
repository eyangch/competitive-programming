#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int k, mdist = 0, start;
        cin >> k;
        string l;
        cin >> l;
        for(start = 0; start < k && l[start] == 'P'; start++){}
        for(int j = start+1; j < k; j++){
            if(l[j] == 'A'){
                mdist = max(mdist, j - start - 1);
                start = j;
                continue;
            }
        }
        mdist = max(mdist, k - start - 1);
        cout << mdist << endl;
    }
    return 0;
}
