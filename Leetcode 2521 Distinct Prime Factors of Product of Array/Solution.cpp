class Solution 
{
public:
vector<int>Factors(int n)
{
  vector<int>v;
  for(int i=1;i<=n;i++)
  {
    if(n%i==0)
    {
      v.push_back(i);
    }
  }
  return v;
}
bool TestPrime(int n)
{
  if(n<2) return false;
  bool test=true;
  for(int j=2;j*j<=n;j++)
  {
    if(n%j==0)
    {
       test=false;
       break;
    }
  }
  return test;
}
    int distinctPrimeFactors(vector<int>& nums) 
    {
        long long product=1;
        unordered_set<int>set1;
        unordered_map<int,int>freq;
        for(int k=0;k<nums.size();k++)
        {
   vector<int> vv=Factors(nums[k]);
            for(int j=0;j<vv.size();j++)
              {
            set1.insert(vv[j]);
        }
        }
        int count=0;
        vector<int>r;
        for(auto it:set1)
            {
                if(TestPrime(it))
                    {
                        freq[it]++;
                    }
            }
        for(auto it:freq)
            {
                r.push_back(it.first);
            }
        count=r.size();
        return count;
    }
}; 
 
