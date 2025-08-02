class Solution 
{
public:
    bool HasZero(int n)
    {
        bool has=false;
        while(n>0)
            {
                int rem=n%10;
                if(rem==0)
                {
                    has=true;
                    break;
                }
                n=n/10;
            }
        return has;
    }
    vector<int> getNoZeroIntegers(int n)
    {
         vector<int>v;
        for(int i=1;i<n;i++)
            {
        int a=i;
                int b=n-i;
                if(!HasZero(a)&&!HasZero(b)&&a<n&&b<n)
                {
                    v.push_back(a);
                    v.push_back(b);
                    break;
                }
            }
        return v;
    }
};
