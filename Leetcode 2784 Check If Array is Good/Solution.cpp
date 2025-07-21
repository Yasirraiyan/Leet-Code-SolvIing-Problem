class Solution 
{
public:
 int findmax(vector<int>&arr)
 {
  int max=arr[0];
  for(int i=1;i<arr.size();i++)
  {
    if(arr[i]>max)
    {
      max=arr[i];
    }
  }
  return max;
 }
    bool isGood(vector<int>& nums) 
    {
        int max=findmax(nums);
        int base=max;
        unordered_map<int,int>freq;
        bool isgood=false;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        if(nums.size()<=base) 
        {
          return isgood;
        }
        if(nums.size()>base)
        {
           if(freq[base]==2&&nums.size()==base+1)
           {
            isgood= true;
           }
           if(freq[base]==2&&nums.size()==base+1)
           {
                for(int i=0;i<nums.size();i++)
                {
                  if(nums[i]!=base)
                  {
                    if(freq[nums[i]]!=1)
                    {
                      isgood=false;
                      break;
                    }
                    else
                    {
                      isgood=true;
                    }
                  }
                }
           }
           else
           {
            return isgood;
           }
        }
        return isgood;
    }
};
