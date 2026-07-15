class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix.size() - i - 1; j++)
                swap(matrix[i][matrix.size() - j - 1], matrix[matrix.size() - j - 1][i]);
    }
};