class Solution 
{
public:
    int maxContainers(int n, int w, int maxWeight) 
    {
         int cell=n*n;
         int totalweight=w*cell;
         int ans;
         if(totalweight<=maxWeight)
         {
             ans=cell;
         }
          if(totalweight>maxWeight)
         {
             ans=maxWeight/w;
         }
         return ans;

    }
};
