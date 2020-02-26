#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, t[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t[i];
    }
    int a = 0, b = N-1, la = -1, lb = N;
    while(a < b){
        la = a;
        lb = b;
        if(t[a] > t[b]){
            t[a] -= t[b];
            t[b] = 0;
            b--;
        }
        else if(t[a] <= t[b]){
            t[b] -= t[a];
            t[a] = 0;
            a++;
        }
    }
    if(lb == a){
        b--;
    }else{
        a++;
    }
    cout << a << " " << N-1-b << endl; 
}
