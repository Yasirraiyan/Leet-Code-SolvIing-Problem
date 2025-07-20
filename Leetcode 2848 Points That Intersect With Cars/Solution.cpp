class Solution 
{
public:
vector<int>GetAll(int low,int high)
{
  vector<int>ans;
  for(int k=low;k<=high;k++)
  {
     ans.push_back(k);
  }
  return ans;
}
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            int low=nums[i][0];
            int high=nums[i][1];
           vector<int> temp=GetAll(low,high);
           for (auto point : temp) 
           {
                v.push_back(point);
            }
        }
        unordered_map<int,int>freq;
        for(int k=0;k<v.size();k++)
        {
          freq[v[k]]++;
        }
        vector<int>vv;
        for(auto it:freq)
        {
          vv.push_back(it.first);
        }
        int ans=vv.size();
        return ans;
    }
};
