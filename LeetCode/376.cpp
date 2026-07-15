class Solution {
public:
    int dp[1000][2];
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0; i < N; i++){
            dp[i][0] = dp[i][1] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
                if(nums[i] < nums[j]){
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
        }
        return max(dp[N-1][0], dp[N-1][1]);
    }
};