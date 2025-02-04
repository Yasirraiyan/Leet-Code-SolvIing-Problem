class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
         int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> ans(cols, vector<int>(rows));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                //matrix[i][j]=ans[j][i];
                ans[j][i]=matrix[i][j];
                
            }
        }
        return ans;
    }
};
