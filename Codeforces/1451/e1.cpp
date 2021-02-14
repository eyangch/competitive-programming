#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int N, a[1<<16], rxor = 0;

int qry(string op, int i, int j){
    cout << op << " " << i << " " << j << endl;
    cout.flush();
    int x; cin >> x;
    if(op == "XOR") rxor ^= x;
    return x;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int n1 = qry("XOR", 1, 2) + (qry("AND", 1, 2) << 1);
    int n2 = qry("XOR", 2, 3) + (qry("AND", 2, 3) << 1);
    int n3 = rxor + (qry("AND", 1, 3) << 1);
    cout.flush();
    a[0] = (n1 - n2 + n3) / 2, a[1] = (n1 + n2 - n3) / 2, a[2] = (-n1 + n2 + n3) / 2;
    for(int i = 3; i < N; i++){
        a[i] = qry("XOR", i, i+1) ^ a[i-1];
    }
    cout << "! ";
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout.flush();
}
