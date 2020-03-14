#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        string s;
        cin >> s;
        int curr = -1, d = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'L') continue;
            d = max(d, i - curr);
            curr = i;
        }
        d = max(d, (int)s.length() - curr);
        cout << d << endl;
    }
    return 0;
}
