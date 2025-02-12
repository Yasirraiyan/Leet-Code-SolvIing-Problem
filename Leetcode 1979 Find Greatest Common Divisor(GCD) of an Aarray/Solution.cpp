class Solution {
public:
int GCD(int a,int b)
{
     while (b != 0) 
     {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

    int findGCD(vector<int>& nums) 
    {
        int small=nums[0];
        int high=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>high)
            {
                high=nums[i];
            }
             if(nums[i]<small)
            {
                small=nums[i];
            }
        }
      int gcd=  GCD(small,high);
      return gcd;
    }
};
