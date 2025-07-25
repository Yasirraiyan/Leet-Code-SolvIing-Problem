class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
{
      int count=0;
        sort(nums.begin(),nums.end());
        int ans;
        for(int j=nums.size()-1;j>=0;j--)
            {
               
                count++;
                if(count==k)
                {
                    ans=nums[j];
                    break;
                }
            }
        return ans;
    }
};
