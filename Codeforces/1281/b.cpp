#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        string s, c; cin >> s >> c;
        for(int i = 0; i < s.length(); i++){
            char m = s[i];
            int midx = i;
            for(int j = s.length() - 1; j > i; j--){
                if(s[j] < m){
                    m = s[j];
                    midx = j;
                }
            }
            if(midx != i){
                swap(s[i], s[midx]);
                break;
            }
        }
        if(s.compare(c) < 0){
            cout << s << endl;
        }else{
            cout << "---" << endl;
        }
    }
    return 0;
}
