#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    unordered_map<int, int> pos;
    cin >> N;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        pos.insert(make_pair(a, b));
    }
    for(pair<int, int> i : pos){
        int go = i.first + i.second;
        if(pos.find(go) != pos.end() && pos[go] == -i.second){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
