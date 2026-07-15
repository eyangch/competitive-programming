class Solution {
public:
    int dyn(vector<int> steps){
        for(int i = steps.size() - 3; i >= 0; i--){
            steps[i] += min(steps[i+1], steps[i+2]);
        }
        return min(steps[0], steps[1]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return dyn(cost);
    }
}; 