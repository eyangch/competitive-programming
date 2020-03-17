#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("cin", "r", stdin);
    int N, a[200000];
    string s;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    cin >> s;
    int through = 0;
    for(int i = 0; i < N-1; i++){
        if(s[i] == '1'){
            through++;
        }else{
            if(through > 0)
                sort(a + i - through, a + i + 1);
            through = 0;
        }
    }
    if(through > 0)
        sort(a + N - 1 - through, a + N);
    for(int i = 0; i < N-1; i++){
        if(a[i] > a[i+1]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
