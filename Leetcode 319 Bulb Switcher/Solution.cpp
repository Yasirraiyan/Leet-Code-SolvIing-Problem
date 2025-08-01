class Solution 
{
public:
int TestPerfectSquare(int n)
    {
        int low=0;
        int high=n;
        bool test=false;
        while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(1LL*mid*mid<n)
                {
                    low=mid+1;
                }
                else if(1LL*mid*mid==n)
                { 
                    return mid;
                }
                else
                {
                    high=mid-1;
                }  
            }
        return high;
    }
    int bulbSwitch(int n) 
    {
        int count=0;
        if(n==0||n==1) return n;
   int ans=TestPerfectSquare(n);
        return ans;
    }
};
