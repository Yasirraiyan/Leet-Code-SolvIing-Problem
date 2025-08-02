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
    int minBitFlips(int start, int goal) 
    {
        int XOR=start^goal;
        int bit=One(XOR);
        return bit;
    }
};
