class Solution 
{
public:
    int findreverse(int n)
    {
        int ans=0;
        while(n>0)
            {
                int d=n%10;
                ans=d+ans*10;
                n/=10;
            }
        return ans;
    }
    bool isSameAfterReversals(int num) 
    {
        bool same=false;
        int a=findreverse(num);
        int b=findreverse(a);
        if(b==num)
        {
            same=true;
        }
        return same;
    }
};
