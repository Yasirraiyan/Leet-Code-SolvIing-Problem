class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
{
        vector<int>v;
        int count=0;
        int ans;
        for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[i].size();j++)
                    {
                        v.push_back(matrix[i][j]);
                    }
            }
        sort(v.begin(),v.end());
        for(int j=0;j<v.size();j++)
            {
                if(k==j+1)
                {
                    ans=v[j];
                    break;
                }
            }
        return ans;
    }
};
