class Solution 
{
public:
bool symmetric(int n)
{
  bool issymmetric=false;
  vector<int>reserve;
  while(n>0)
  {
    int rem=n%10;
    reserve.push_back(rem);
    n=n/10;
  }
  if (reserve.size() % 2 != 0) 
  {
     return false;
   }
  int low=0;
  int high=reserve.size()-1;
  int mid=(low+high)/2;
  int sum1=0;
  int sum2=0;
  for(int i=0;i<=mid;i++)
  {
    sum1+=reserve[i];
  }
  for(int j=mid+1;j<reserve.size();j++)
  {
    sum2+=reserve[j];
  }
  if(sum1==sum2)
  {
    issymmetric=true;
  }
return issymmetric;
}
    int countSymmetricIntegers(int low, int high)
     {
        int count=0;
        for(int k=low;k<=high;k++)
        {
          if(symmetric(k))
          {
            count++;
          }
        }
        return count;
    }
};
