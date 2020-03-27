#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("clumsy.in", "r", stdin);
    freopen("clumsy.out", "w", stdout);
    string s; cin >> s;
    int ops = 0, open = 0;
    for(int i = 0; i < s.length(); i++){
        if(open == 0 && s[i] == ')'){
            open++;
            ops++;
        }else if(s[i] == '('){
            open++;
        }else{
            open--;
        }
    }
    cout << ops + open / 2 << endl;
    return 0;
}
