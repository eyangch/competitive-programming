/*
ID: sireric1
LANG: C++11
TASK: lgame
*/

#include <bits/stdc++.h>

using namespace std;

int value[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
vector<long long> dict;
set<long long> has;
map<long long, vector<string>> id2str;
set<string> sub;
string str;
int mxval = 0;
set<pair<string, string>> ans;

long long getID(string s){
    sort(s.begin(), s.end());
    long long mp = pow(27, 6);
    long long ret = 0;
    for(int i = 0; i < (int)s.size(); i++){
        ret += (s[i] - 96) * mp;
        mp /= 27;
    }
    return ret;
}

void dfs(string cur, int idx){
    if(idx == (int)str.size()){
        sub.insert(cur);
        return;
    }
    dfs(cur, idx+1);
    cur += str[idx];
    dfs(cur, idx+1);
}

int calcv(string s){
    int ret = 0;
    for(char i : s){
        ret += value[i-'a'];
    }
    return ret;
}

int32_t main(){
    ifstream dictf("lgame.dict");
    while(true){
        string nxt; dictf >> nxt;
        if(nxt == ".") break;
        long long id = getID(nxt);
        id2str[id].push_back(nxt);
        dict.push_back(id);
        has.insert(id);
    }
    sort(dict.begin(), dict.end());
    freopen("lgame.in", "r", stdin);
    freopen("lgame.out", "w", stdout);
    cin >> str;
    sort(str.begin(), str.end());
    dfs("", 0);
    for(string i : sub){
        int currval = calcv(i);
        if(currval < mxval){
            continue;
        }
        for(long long id : dict){
            vector<string> opt = id2str[id];
            for(string j : opt){
                string cstr = j;
                int occ[26];
                fill(occ, occ+26, 0);
                for(char k : i){
                    occ[k-'a']++;
                }
                bool good = true;
                for(char k : cstr){
                    if(--occ[k-'a'] < 0){
                        good = false;
                        break;
                    }
                }
                if(!good) continue;
                string fnd = "";
                for(int k = 0; k < 26; k++){
                    for(int l = 0; l < occ[k]; l++){
                        fnd += (char)(k+'a');
                    }
                }
                if(fnd == "" || has.count(getID(fnd))){
                    if(currval > mxval){
                        mxval = currval;
                        ans.clear();
                    }
                }
                if(fnd == ""){
                    ans.insert({cstr, ""});
                }else if(has.count(getID(fnd))){
                    for(string k : id2str[getID(fnd)]){
                        if(cstr > k) continue;
                        ans.insert({cstr, k});
                    }
                }
            }
        }
    }
    cout << calcv((*ans.begin()).first) + calcv((*ans.begin()).second) << endl;
    for(pair<string, string> i : ans){
        if(i.second == ""){
            cout << i.first << endl;
        }else{
            cout << i.first << " " << i.second << endl;
        }
    }
}
