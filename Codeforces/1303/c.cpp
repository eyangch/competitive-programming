#include <bits/stdc++.h>

using namespace std;

int c2i(char x){
    return ((int)x - 97);
}

char i2c(int x){
    return ((char)x + 97);
}

int main(){
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        string s;
        cin >> s;
        if(s.length() == 1){
            string ret = s;
            for(int i = 0; i < 26; i++){
                if(i2c(i) != s[0]){
                    ret += i2c(i);
                }
            }
            cout << "YES" << endl << ret << endl;
            continue;
        }
        set<int> graph[26];
        graph[c2i(s[0])].insert(c2i(s[1]));
        for(int i = 1; i < s.length()-1; i++){
            graph[c2i(s[i])].insert(c2i(s[i-1]));
            graph[c2i(s[i])].insert(c2i(s[i+1]));
        }
        graph[c2i(s[s.length() - 1])].insert(c2i(s[s.length() - 2]));
        string unused = "";
        int ones = 0, twos = 0, bad = 0;
        for(int i = 0; i < 26; i++){
            if(graph[i].size() == 0){
                unused += i2c(i);
            }else if(graph[i].size() == 1){
                ones++;
            }else if(graph[i].size() == 2){
                twos++;
            }else{
                bad++;
            }
        }
        if((ones < 2 && twos > 0) || bad > 0){
            cout << "NO" << endl;
            continue;
        }
        string use = "";
        queue<int> bfs;
        set<int> been;
        for(int i = 0; i < 26; i++){
            if(graph[i].size() == 1){
                bfs.push(i);
                been.insert(i);
                break;
            }
        }
        while(!bfs.empty()){
            int idx = bfs.front();
            bfs.pop();
            use += i2c(idx);
            for(int i : graph[idx]){
                if(been.find(i) != been.end()){
                    continue;
                }
                been.insert(i);
                bfs.push(i);
            }
        }
        cout << "YES" << endl << use + unused << endl;
    }
    return 0;
}
