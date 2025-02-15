class Solution 
{
public:
    int findMaxK(vector<int>& nums)
{
        vector<int>reserve;
        for(int i=0;i<nums.size();i++)
        {
           for(int j=i+1;j<nums.size();j++)
           {
            if(i!=j)
            {
                if(nums[i]==-nums[j])
                {
                    if(nums[i]>0)
                    {

                    
                    reserve.push_back(nums[i]);
                    }
                    if(nums[j]>0)
                    {

                    
                    reserve.push_back(nums[j]);
                    }
                }

            }
           }
        }
         if (reserve.empty()) 
         {
            return -1; // No valid elements found
        }
         int max=reserve[0];
        for(int k=1;k<reserve.size();k++)
        {
          //  int max=reserve[0];
            if(reserve[k]>max)
            {
                max=reserve[k];
            }
            //else
           // max=-1;

        }
        return max;
    }
};
