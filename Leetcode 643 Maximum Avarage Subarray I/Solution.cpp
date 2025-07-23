class Solution 
{
public:

    double findMaxAverage(vector<int>& nums, int k) 
    {
       int sum=0;
       for(int i=0;i<k;i++)
       {
        sum+=nums[i];
       }
       int maxsum=sum;
       int windowsum=sum;
       for(int j=k;j<nums.size();j++)
       {
            sum+=nums[j]-nums[j-k];
            maxsum=std::max(sum,maxsum);
       }
       double ans=(double)maxsum/k;
       return ans;
    }
};
