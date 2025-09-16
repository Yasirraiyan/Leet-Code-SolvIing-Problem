class Solution {
public:
 int findmax(vector<int>&arr)
 {
    int max=arr[0];
    for(int j=1;j<arr.size();j++)
    {
        if(arr[j]>max)
        {
            max=arr[j];
        }
    }
    return max;
 }
    int getMaximumGenerated(int n) 
    {
         if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int>nums(n+1,0);
        int i=2;
        nums[0]=0;
        nums[1]=1;
        while(i<=n)
        {
            if(i%2==0)
            {

            
          nums[i]=nums[i/2];
            }
            else
            {
                nums[i]=nums[i/2]+nums[i/2+1];
            }
            i++;
        }
        int ans=findmax(nums);
        return ans;
    }
};
