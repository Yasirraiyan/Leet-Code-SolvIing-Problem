class Solution 
{
public:
  int digitsum(int n)
  {
    int sum=0;
    while(n>0)
    {
      sum+=n%10;
      n=n/10;
    }
    return sum;
  }
    int countBalls(int lowLimit, int highLimit)
     {
        int n=highLimit-lowLimit+1;
        unordered_map<int,int>freq;
        for(int i=lowLimit;i<=highLimit;i++)
        {
       
            freq[digitsum(i)]++;
         
        }
        vector<int>reserve;
        for(auto it:freq)
        {
            reserve.push_back(it.second);
        }
        int max=reserve[0];
        for(int j=1;j<reserve.size();j++)
        {
          if(reserve[j]>max)
          {
            max=reserve[j];
          }
        }
        return max;

    }
};
