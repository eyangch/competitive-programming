#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    set<int> x;
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        x.insert(c);
    }
    set<int>::iterator it = x.begin();
    if(x.size() < 2){
        cout << "NO" << endl;
    }else{
        advance(it, 1);
        cout << (*it) << endl;
    }
    return 0;
}

