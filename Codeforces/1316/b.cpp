#include <bits/stdc++.h>

using namespace std;

string op(string s, int k){
    if(k == s.length()){
        reverse(s.begin(), s.end());
        return s;
    }
    string start = s.substr(k - 1), other = s.substr(0, k - 1);
    if(k % 2 == s.length() % 2){
        reverse(other.begin(), other.end());
    }
    return start + other;
}

int main(){
    int T; cin >> T;
    for(int tc = 0; tc < T; tc++){
        int N;
        string s;
        cin >> N >> s;
        string optstring = s;
        int optk = 1;
        for(int i = 2; i <= N; i++){
            string oped = op(s, i);
            if(optstring.compare(oped) > 0){
                optstring = oped;
                optk = i;
            }
        }
        cout << optstring << endl << optk << endl;
    }
    return 0;
}
