#include <bits/stdc++.h>

using namespace std;

int main(){
    string x;
    vector<string> text;
    int maxSize = 0;
    bool alternate = false;
    while(getline(cin, x)){
        maxSize = max(maxSize, (int)x.length());
        text.push_back(x);
    }
    for(int i = 0; i < maxSize + 2; i++) cout << '*';
    cout << endl;
    for(int i = 0; i < text.size(); i++){
        cout << '*';
        int diff = maxSize - text[i].length();
        if(diff % 2 == 0){
            for(int j = 0; j < diff / 2; j++){
                cout << ' ';
            }
            cout << text[i];
            for(int j = 0; j < diff / 2; j++){
                cout << ' ';
            }
        }else{
            for(int j = 0; j < diff / 2 + alternate; j++){
                cout << ' ';
            }
            cout << text[i];
            alternate = !alternate;
            for(int j = 0; j < diff / 2 + alternate; j++){
                cout << ' ';
            }
        }
        cout << '*' << endl;
    }
    for(int i = 0; i < maxSize + 2; i++) cout << '*';
    cout << endl;
    return 0;
}
