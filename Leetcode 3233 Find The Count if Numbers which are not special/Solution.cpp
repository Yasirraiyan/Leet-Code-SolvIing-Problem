class Solution 
{
public:
   
    int Sqrt(int n)
    {
        int low=0;
        int high=n;
        bool check=false;
        int ans=0;
        while(low<=high)
            {
                int mid=low+(high-low)/2;
                
                if(1LL*mid*mid<=n)
                {
                    ans=mid;
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        return ans;
    }
    bool CheckPrime(int n)
    {
        bool check=true;
        if(n<2) return false;
        for(int j=2;1LL*j*j<=n;j++)
            {
                if(n%j==0)
                {
                    check=false;
                    break;
                }
            }
        return check;
    }
   

    int nonSpecialCount(int l, int r)
    {
        int total=r-l+1;
        int special=0;
        int limit=Sqrt(r);
        for(int k=2;k<=limit;k++)
            {
                if(CheckPrime(k))
                {
                int sq=1LL*k*k;
                if(sq>r) break;
                if(sq>=l)//&&CheckSpecial(sq))//sq<=r)
                {
                    special++;
                }
            }
            }
        int nonspecial=total-special;
                
        return nonspecial;
    }
};
