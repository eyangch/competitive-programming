class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> scores(nums.size());
        scores[0] = nums[0];
        int l = scores[0];
        for(int i = 1; i < nums.size(); i++){
            scores[i] = max(scores[i-1] + nums[i], nums[i]);
            l = max(scores[i], l);
        }
        return l;
    }
};