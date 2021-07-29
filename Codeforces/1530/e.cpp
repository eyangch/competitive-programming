#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T;
string s;

int32_t main(){
    eat.tie(0) -> sync_with_stdio(0);
    eat >> T;
    while(T--){
        eat >> s;
        map<char, int> c;
        for(char i : s) c[i]++;
        char fnd = 0;
        for(pair<char, int> i : c){
            if(i.second == 1){
                fnd = i.first;
                break;
            }
        }
        if(fnd){
            moo << fnd;
            for(pair<char, int> i : c){
                if(i.first == fnd) continue;
                moo << string(i.second, i.first);
            }
            moo << endl;
            continue;
        }
        if((int)c.size() == 1) moo << s << endl;
        if((int)c.size() == 2){
            auto it = c.begin();
            char c1 = it->first;
            int ct1 = it->second;
            it++;
            char c2 = it->first;
            int ct2 = it->second;
            if(ct1 - 2 > ct2){
                moo << c1 << string(ct2, c2) << string(ct1-1, c1) << endl;
            }else{
                if(ct1 == 1) moo << c1;
                else moo << c1 << c1;
                for(int i = 0; i < ct1-2;  i++){
                    moo << c2 << c1;
                }
                moo << string(ct2 - (ct1-min(ct1, 2LL)), c2) << endl;
            }
        }
        if((int)c.size() > 2){
            auto it = c.begin();
            char c1 = it->first;
            int ct1 = it->second;
            it++;
            char c2 = it->first;
            int ct2 = it->second;
            it++;
            char c3 = it->first;
            int ct3 = it->second;
            it--;
            int cto = 0;
            for(; it != c.end(); it++){
                cto += it->second;
            }
            if(ct1 - 2 > cto){
                moo << c1 << c2 << string(ct1-1, c1) << c3 << string(ct2-1, c2) << string(ct3-1, c3);
                auto it = c.begin();
                it++, it++, it++;
                for(; it != c.end(); it++){
                    moo << string(it->second, it->first);
                }
                moo << endl;
            }else{
                int cur1 = 2;
                if(ct1 == 1) moo << c1;
                else moo << c1 << c1;
                auto it = c.begin();
                it++;
                for(; it != c.end(); it++){
                    for(int i = 0; i < it->second; i++){
                        moo << it->first;
                        if(cur1 < ct1){
                            moo << c1;
                            cur1++;
                        }
                    }
                }
                moo << endl;
            }
        }
    }
}
