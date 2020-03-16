#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    string s;
    cin >> N >> s;
    char look = 'z';
    while(look >= 'a'){
        bool chglook = true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == look){
                if((i > 0 && s[i-1] == look - 1) || (i < N-1 && s[i+1] == look - 1)){
                    s.erase(i, 1);
                    chglook = false;
                }
            }
        }
        if(chglook)
            look--;
    }
    cout << N - s.length() << endl;
    return 0;
}
