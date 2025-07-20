class Solution 
{
public:
    int pivotInteger(int n) 
    {
        int totalsum=0;
        int rightsum=0;
        int leftsum=0;
        int pivot=-1;
        for(int i=1;i<=n;i++)
        {
          totalsum+=i;
        }
        for(int j=1;j<=n;j++)
        {
          rightsum=totalsum-leftsum;
         leftsum+=j;
         if(leftsum==rightsum)
         {
          pivot=j;
          break;
         }

        }
return pivot;
    }
};
