#include <bits/stdc++.h>

using namespace std;

int main(){
   string n;
   cin >> n;
   int lucky = 0;
   for(int i = 0; i < n.length(); i++){
       if(n[i] == '4' || n[i] == '7'){
            lucky++;
       }
   }
   string luckstr = to_string(lucky);
   for(int i = 0; i < luckstr.length(); i++){
        if(!(luckstr[i] == '4' || luckstr[i] == '7')){
            cout << "NO" << endl;
            return 0;
        }
   }
   cout << "YES" << endl;
}
