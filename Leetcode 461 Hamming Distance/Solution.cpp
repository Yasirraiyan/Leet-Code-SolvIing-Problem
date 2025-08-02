class Solution 
{
public:
    int One(int n)
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
    int hammingDistance(int x, int y)
    {
        int result=x^y;
        int hd=One(result);
        return hd;
    }
};
