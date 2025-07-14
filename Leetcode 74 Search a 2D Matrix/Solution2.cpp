class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
  bool find=false;
        for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[i].size();j++)
                    {
                        v.push_back(matrix[i][j]);
                    }
            }
        sort(v.begin(),v.end());
        int low=0;
        int high=v.size()-1;
        int mid;
        while(low<=high)
            {
                mid=low+(high-low)/2;
                if(v[mid]==target)
                {
                    find=true;
                    break;
                }
                else if(v[mid]<target)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        return find;
    }
};
