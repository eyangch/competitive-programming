#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, D;
    string s;
    cin >> N >> D >> s;
    int loc = 0, ret = 0;
    while(loc != N-1){
        int nloc = -1;
        for(int i = loc + D; i > loc; i--){
            if(s[i] == '1'){
                nloc = i;
                ret++;
                break;
            }
        }
        if(nloc == -1){
            cout << -1 << endl;
            return 0;
        }
        loc = nloc;
    }
    cout << ret << endl;
    return 0;
}
