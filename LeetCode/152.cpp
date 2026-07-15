class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mn = nums[0], mx = nums[0], ans = nums[0];
        nums.erase(nums.begin());
        for(int i : nums){
            int tmn = mn;
            mn = min({mn * i, i, mx * i});
            mx = max({tmn * i, i, mx * i});
            ans = max(ans, mx);
        }
        return ans;
    }
};