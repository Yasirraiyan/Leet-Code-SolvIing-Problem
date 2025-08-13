class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
{
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
         vector<int>v;
         for(auto it:freq)
         {
            v.push_back(it.second);
         }
         sort(v.begin(),v.end());
         reverse(v.begin(),v.end());
         vector<int>vv;
         for(int j=0;j<v.size();j++)
         {
            vv.push_back(v[j]);
            if(vv.size()==k)
            {
                break;
            }
         }
         vector<int>ans;
         for(auto it:freq)
         {
         for(int j=0;j<vv.size();j++)
         {
             if(it.second==vv[j])
             {
                ans.push_back(it.first);
                 vv.erase(vv.begin() + j); // remove used frequency
                    break; 
             }
         }
         if(ans.size()==k) break;
         }
         return ans;
    }
};
