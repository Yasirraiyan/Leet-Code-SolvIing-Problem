class Solution 
{
public:
   int countbit(int n)
   {
    int count=0;
    while(n>0)
    {

    
    int rem=n%2;
    if(rem==1)
    {
      count++;
    }
    n=n/2;
    }
    return count;
   }
    vector<int> countBits(int n) 
    {
        
       vector<int>ans;
       for(int i=0;i<=n;i++)
       {
        ans.push_back(countbit(i));
       }
       return ans;
    }
};
