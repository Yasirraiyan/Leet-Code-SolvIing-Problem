class Solution 
{
public:
    int heightChecker(vector<int>& heights) 
    {
        vector<int>v;
        for(int i=0;i<heights.size();i++)
        {
            v.push_back(heights[i]);
        }
        vector<int>vv;
        sort(heights.begin(),heights.end());
        for(int j=0;j<heights.size();j++)
        {
            vv.push_back(heights[j]);
        }
        int count=0;
        for(int j=0;j<v.size();j++)
        {
           
                if(v[j]!=vv[j])
                {
                  count++;
                }
            
        }
        return count;
    }
};
