#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int end = 0;
        for(int i = 1; i < n; i++){
            end = ((end - k) % i + i) % i + 1;
        }
        end = (end - k + n) % n;
        int offset = n-end;
        return offset;
    }
};