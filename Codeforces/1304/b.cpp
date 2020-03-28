#include <bits/stdc++.h>

using namespace std;

string rev(string s){
    for(int i = 0; i < s.length() / 2; i++){
        swap(s[i], s[s.length() - 1 - i]);
    }
    return s;
}

int main(){
    int N, M;
    cin >> N >> M;
    string s[N];
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }
    int ret = 0;
    string center = "";
    for(int i = 0; i < N; i++){
        if(s[i] == rev(s[i])){
            ret++;
            center = s[i];
            break;
        }
    }
    vector<string> out;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(s[i] == rev(s[j])){
                ret += 2;
                out.push_back(s[i]);
                break;
            }
        }
    }
    cout << ret * M << endl;
    if(out.size() != 0){
        for(int i = 0; i < out.size(); i++){
            cout << out[i];
        }
        cout << center;
        for(int i = out.size() - 1; i > 0; i--){
            cout << rev(out[i]);
        }
        cout << rev(out[0]) << endl;
    }else{
        cout << center << endl;
    }
    return 0;
}
