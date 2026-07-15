class Solution {
public:
    int minSteps(int N) {
        int cpf = 2;
        int ans = 0;
        while(N > 1){
            while(N % cpf == 0){
                ans += cpf;
                N /= cpf;
            }
            cpf++;
        }
        return ans;
    }
};