#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string a, b, c;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> a >> b >> c;
    bool ok[2] = {0, 0};
    for(int t = 0; t < 2; t++){
        for(int i = 0; i < (int)a.size(); i++){
            if(a.substr(i, b.size()) == b){
                for(int j = i+b.size(); j < (int)a.size(); j++){
                    if(a.substr(j, c.size()) == c){
                        ok[t] = true;
                        break;
                    }
                }
                break;
            }
        }
        reverse(a.begin(), a.end());
    }
    if(ok[0] && ok[1]) moo << "both" << endl;
    else if(ok[0]) moo << "forward" << endl;
    else if(ok[1]) moo << "backward" << endl;
    else moo << "fantasy" << endl;
}
