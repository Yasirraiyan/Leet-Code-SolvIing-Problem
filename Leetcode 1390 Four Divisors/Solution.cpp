class Solution 
{
public:
  bool Check(int n)
  {
    bool check=false;
     int count=0;
    vector<int>v;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
           count++;
           v.push_back(i);
            if (i != n / i) // avoid double-counting perfect square root
            {
                count++;
                v.push_back(n / i);
            }
             if (count > 4) break;
        }
        }
        if(count==4)
        {
            check=true;
          // break;
        }
    
    return check;
  }
 int divisors(int n)
 {
    int sum=0;
   vector<int>v;
   for(int k=1;k<=n;k++)
   {
    if(n%k==0)
    {
        v.push_back(k);
    }
   }
    for(int j=0;j<v.size();j++)
    {
        sum+=v[j];
    }
    return sum;
 }
    int sumFourDivisors(vector<int>& nums) 
    {
        int sum=0;
        for(int k=0;k<nums.size();k++)
        {
            if(Check(nums[k]))
            {
                sum+=divisors(nums[k]);
            }
        }
        return sum;
    }
};
