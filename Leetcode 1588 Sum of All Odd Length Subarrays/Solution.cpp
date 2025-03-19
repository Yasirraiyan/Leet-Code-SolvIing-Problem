class Solution 
{
public:
  int sum(vector<int>&nums)
  {
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
      sum+=nums[i];
    }
    return sum;
  }
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
      int result=0;
        for(int i=0;i<arr.size();i++)
        {
          for(int j=i;j<arr.size();j++)
          {
            if((j-i+1)%2!=0)
            {
                  vector<int> tempSubarray;
            
            
            for(int k=i;k<=j;k++)
            {
             //vector<int> tempSubarray;
            
                 tempSubarray.push_back(arr[k]);
              
            }
            result+=sum(tempSubarray);
            }
          }
        }
        return result;
    }
};
