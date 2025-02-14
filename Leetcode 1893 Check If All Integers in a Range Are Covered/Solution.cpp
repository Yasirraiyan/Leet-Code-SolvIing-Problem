class Solution {
public:
vector<int> rangesinteger(int left,int right)
{
    vector<int>ans;
    for(int i=left;i<=right;i++)
    {
        ans.push_back(i);
    }
    return ans;
}
    bool isCovered(vector<vector<int>>& ranges, int left, int right) 
    {
        bool cover=true;
      vector<int> c=  rangesinteger( left, right);
        for(int i=0;i<c.size();i++)
        {
             bool currentCovered = false;
            for(int j=0;j<ranges.size();j++)
            {
                if(ranges[j][0]<=c[i]&&c[i]<=ranges[j][1])
                {
                    //cover=true;
                     currentCovered = true;
                    break;

                }
            }
             if (!currentCovered) 
             {
                cover = false;
                break;
            }
        }
        return cover;
    }
};
