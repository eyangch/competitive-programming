#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, r = 0, l = 0;
    cin >> N;
    string s;
    cin >> s;
    for(int i = 0; i < N; i++){
        if(s[i] == 'R') r++;
        else l++;
    }
    cout << r + l + 1 << endl;
    return 0;
}
