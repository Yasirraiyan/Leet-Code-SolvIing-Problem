class Solution {
public:
    int maximizeSum(vector<int>& nums, int k)
     {
        sort(nums.begin(),nums.end());
        int count=0;
        int sum=0;
        while(count<k)
        {
           sum+=nums[nums.size()-1];
           nums[nums.size()-1]=nums[nums.size()-1]+1;
           count++;
           if(count==k) break;
        }
        return sum;
    }
};
