class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size() / 2; j++){
                int tmp = A[i][j];
                A[i][j] = A[i][A[i].size() - 1 - j];
                A[i][A[i].size() - 1 - j] = tmp;
            }
        }
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < A[i].size(); j++)
                (A[i][j] == 0) ? (A[i][j] = 1) : (A[i][j] = 0);
        return A;
    }
};