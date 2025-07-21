class Solution 
{
public:
  bool CheckPrime(int n)
  {
    bool isprime=true;
    if(n<=1) 
    {
      isprime=false;
    }
    for(int i=2;i*i<=n;i++)
    {
      if(n%i==0)
      {
        isprime=false;
        break;
      }
    }
    return isprime;
  }
    bool checkPrimeFrequency(vector<int>& nums) 
    {
        bool check=false;
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
          freq[nums[i]]++;
        }
        for(auto it:freq)
        {
          if(CheckPrime(it.second))
          {
            check=true;
            break;
          }
        }
        return check;
    }
};
