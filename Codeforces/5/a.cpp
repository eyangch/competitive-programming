#include <bits/stdc++.h>

using namespace std;

int main(){
    int p = 0, ret = 0;
    string x;
    while(getline(cin, x)){
        if(x[0] =='\0') break;
        if(x[0] == '+') p++;
        else if(x[0] == '-') p--;
        else{
            int col = x.find(':');
            ret += p * (x.length() - col - 1);
        }
    }
    cout << ret << endl;
    return 0;
}
