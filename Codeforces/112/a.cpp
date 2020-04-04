#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    string s1, s2; cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++){
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        if(s1[i] < s2[i]){
            cout << -1 << endl;
            return 0;
        }else if(s1[i] > s2[i]){
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}

