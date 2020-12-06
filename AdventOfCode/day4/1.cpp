#include <bits/stdc++.h>
#define f first
#define s second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <typename T1, typename T2>
ostream &operator <<(ostream &os, pair<T1, T2> p){os << p.first << " " << p.second; return os;}
template <typename T>
ostream &operator <<(ostream &os, vector<T> &v){for(T i : v)os << i << ", "; return os;}
template <typename T>
ostream &operator <<(ostream &os, set<T> s){for(T i : s) os << i << ", "; return os;}
template <typename T1, typename T2>
ostream &operator <<(ostream &os, map<T1, T2> m){for(pair<T1, T2> i : m) os << i << endl; return os;}

string v[] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

signed main(){
    freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL); 
    string nxt;
    int ans =0;
    int cnt = 0;
    int prevc = 0;
    string prev;
    while(getline(cin, nxt)){
        if(nxt == ""){
            ans += (cnt == 7);
            cnt = 0;
        }else{
            for(int i = 0; i <= (int)nxt.size(); i++){
                if(i < (int)nxt.size() && nxt[i] == ':'){
                    string s = nxt.substr(i-3, 3);
                    prev = s;
                    for(string j : v){
                        cnt += (s == j);
                    }
                    prevc = i;
                }
                if(i == (int)nxt.size() || nxt[i] == ' '){
                    string s = nxt.substr(prevc+1, i-prevc-1);
                    cout << s << " " << prev << endl;
                    if(prev == "byr"){
                        if((int)s.size() != 4 || stoi(s) < 1920 || stoi(s) > 2002){
                            cnt = 931983;
                        }
                    }if(prev == "iyr"){
                        if((int)s.size() != 4 || stoi(s) < 2010 || stoi(s) > 2020){
                            cnt = 931983;
                        }
                    }if(prev == "eyr"){
                        if((int)s.size() != 4 || stoi(s) < 2020 || stoi(s) > 2030){
                            cnt = 931983;
                        }
                    }if(prev == "hgt"){
                        if((int)s.size() < 4){
                            cnt = 9999;
                        }else{
                            cout << s.substr(0, s.size()-2) << endl;
                            int f1 = stoi(s.substr(0, s.size()-2));
                            string f2 = s.substr(s.size()-2);
                            //cout << f1 << endl;
                            if(f2 == "in"){
                                if(f1 < 59 || f1 > 76){
                                    cnt = 9999;
                                }
                            }else if(f2 == "cm"){
                                if(f1 < 150 || f1 > 193){
                                    cnt = 9999;
                                }
                            }else{
                                cnt = 9999;
                            }
                        }
                    }if(prev == "hcl"){
                        if((int)s.size() != 7 || s[0] != '#'){
                            cnt = 9999;
                        }else{
                            for(int j = 1; j < (int)s.size(); j++){
                                if((s[j] < '0' || s[j] > '9') && (s[j] < 'a' || s[j] > 'f')){
                                    cnt = 9999;
                                }
                            }
                        }
                    }if(prev == "ecl"){
                        string ok[] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
                        bool good = false;
                        for(string j : ok){
                            if(s == j){
                                good = true;
                                break;
                            }
                        }
                        if(!good){
                            cnt = 9999;
                        }
                    }if(prev == "pid"){
                        if((int)s.size() != 9){
                            cnt = 99999; 
                        }else{
                            for(char j : s){
                                if(j < '0' || j > '9'){
                                    cnt = 9999;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans + (cnt == 7) << endl;
    return 0;
}



