#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

string s;
int N, r[1000000];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    N = s.length();
    int l = 0, h = N - 1;
    for(int i = 0; i < N; i++){
        if(s[i] == 'l'){
            r[h] = i + 1;
            h--;
        }else{
            r[l] = i + 1;
            l++;
        }
    }
    for(int i = 0; i < N; i++) cout << r[i] << endl;
}
