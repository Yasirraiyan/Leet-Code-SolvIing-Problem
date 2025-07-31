class Solution 
{
public:
    int smallestEvenMultiple(int n)
    {
        int small;
        for(int i=n;i<=pow(2,31)-1;i++)
            {
                if(i%2==0&&i%n==0)
                {
                    small=i;
                    break;
                }
            }
        return small;
    }
};
