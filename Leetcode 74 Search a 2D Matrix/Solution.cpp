class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
        unordered_set<int>set1;
        bool find=false;
        for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[i].size();j++)
                    {
                        set1.insert(matrix[i][j]);
                    }
            }
        if(set1.find(target)!=set1.end())
        {
            find=true;
        }
        return find;
    }
};
