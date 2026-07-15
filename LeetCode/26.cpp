class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int dup = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == dup){
                nums.erase(nums.begin() + i - 1);
                i--;
            }
            dup = nums[i];
        }
        return nums.size();
    }
};