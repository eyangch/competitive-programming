#include <bits/stdc++.h>

using namespace std;

void pressBtn(bool (&lights)[6], bool btn[6]){
    for(int i = 0; i < 6; i++){
        if(btn[i]){
            lights[i] = !lights[i];
        }
    }
}

string b2s(bool lights[6]){
    string ret;
    for(int i = 0; i < 6; i++){
        ret += (char)(lights[i] + 48);
    }
    return ret;
}

bool works(bool lights[6], vector<int> on, vector<int> off){
    for(int i : on){
        if(!lights[i-1]){
            return false;
        }
    }
    for(int i : off){
        if(lights[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");
    int N, C;
    vector<int> on, off;
    set<string> possib;
    bool b[4][6] = {{1, 1, 1, 1, 1, 1}, {1, 0, 1, 0, 1, 0}, {0, 1, 0, 1, 0, 1}, {1, 0, 0, 1, 0, 0}};
    fin >> N >> C;
    while(true){
        int x;
        fin >> x;
        if(x == -1){
            break;
        }else{
            x %= 6;
            if(x == 0) x = 6;
            on.push_back(x);
        }
    }
    while(true){
        int x;
        fin >> x;
        if(x == -1){
            break;
        }else{
            x %= 6;
            if(x == 0) x = 6;
            off.push_back(x);
        }
    }
    for(int i : on){
        for(int j : off){
            if(i == j){
                fout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }
    if(C > -1 && C != 1){
        bool l[6] = {1, 1, 1, 1, 1, 1};
        if(works(l, on, off)){
            possib.insert(b2s(l));
        }
    }
    if(C > 0 && C != 2){
        for(int i = 0; i < 4; i++){
            bool l[6] = {1, 1, 1, 1, 1, 1};
            pressBtn(l, b[i]);
            if(works(l, on, off)){
                possib.insert(b2s(l));
            }
        }
    }
    if(C > 1 && C != 3){
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                bool l[6] = {1, 1, 1, 1, 1, 1};
                pressBtn(l, b[i]);
                pressBtn(l, b[j]);
                if(works(l, on, off)){
                    possib.insert(b2s(l));
                }
            }
        }
    }
    if(C > 2 && C != 4){
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                for(int k = j + 1; k < 4; k++){
                    bool l[6] = {1, 1, 1, 1, 1, 1};
                    pressBtn(l, b[i]);
                    pressBtn(l, b[j]);
                    pressBtn(l, b[k]);
                    if(works(l, on, off)){
                        possib.insert(b2s(l));
                    }
                }
            }
        }
    }
    if(C > 3 && C != 5){
        for(int i = 0; i < 4; i++){
            for(int j = i + 1; j < 4; j++){
                for(int k = j + 1; k < 4; k++){
                    for(int h = k + 1; h < 4; h++){
                        bool l[6] = {1, 1, 1, 1, 1, 1};
                        pressBtn(l, b[i]);
                        pressBtn(l, b[j]);
                        pressBtn(l, b[k]);
                        pressBtn(l, b[h]);
                        if(works(l, on, off)){
                            possib.insert(b2s(l));
                        }
                    }
                }
            }
        }
    }
    for(string x : possib){
        for(int i = 0; i < N; i++){
            fout << x[i%6];
        }
        fout << endl;
    }
    if(possib.size() == 0){
        fout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
