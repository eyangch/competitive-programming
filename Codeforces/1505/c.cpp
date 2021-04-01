#include <bits/stdc++.h>
#define endl "\n"
#define eat cin
#define moo cout

using namespace std;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    string s; eat >> s;
    if((int)s.length() < 3){
        moo << "YES" << endl;
        return 0;
    }
    int x = (s[0]-'A') + (s[1]-'A');
    x %= 26;
    for(int i = 2; i < (int)s.length(); i++){
        int y = s[i]-'A';
        if(x != y){
            moo << "NO" << endl;
            return 0;
        }
        x = (s[i-1] - 'A' + y) % 26;
    }
    moo << "YES" << endl;
}
