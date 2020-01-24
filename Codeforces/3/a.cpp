#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    vector<string> t;
    cin >> a >> b;
    int x1, y1, x2, y2, vert = 0, horz = 0;
    x1 = (int)a[0] - 97;
    y1 = (int)a[1] - 49;
    x2 = (int)b[0] - 97;
    y2 = (int)b[1] - 49;
    if(x1 < x2){
        horz = 1;
    }else{
        horz = -1;
    }
    if(y1 < y2){
        vert = 1;
    }else{
        vert = -1;
    }
    while(x1 != x2 || y1 != y2){
        if(x1 == x2) horz = 0;
        if(y1 == y2) vert = 0;
        x1 += horz;
        y1 += vert;
        string r = "";
        if(horz == 1) r += 'R';
        else if(horz == -1) r += 'L';
        if(vert == 1) r += 'U';
        else if(vert == -1) r += 'D';
        t.push_back(r);
    }
    cout << t.size() << endl;
    for(string i : t) cout << i << endl;
    return 0;
}
