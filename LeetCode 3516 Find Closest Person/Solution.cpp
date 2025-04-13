class Solution 
{
public:
    int findClosest(int x, int y, int z) 
    {
        int a=abs(z-x);
        int b=abs(z-y);
        int ans;
        if(a<b)
        {
          ans=1;
        }
        else if(a==b)
        {
            ans=0;
        }
        else
        {
           ans=2;
        }
        return ans;
    }
};
