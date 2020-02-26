#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> okay;
    unordered_map<string, int> data;
    for(int i = 0; i < N; i++){
        string x;
        cin >> x;
        if(data.find(x) == data.end()){
            data.insert(make_pair(x, 0));
            okay.push_back("OK");
        }else{
            data[x]++;
            okay.push_back(x + to_string(data[x]));
        }
    }
    for(int i = 0; i < N; i++){
        cout << okay[i] << endl;
    }
    return 0;
}
