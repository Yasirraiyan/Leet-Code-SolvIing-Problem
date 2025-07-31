class Solution 
{
public:
    int findreverse(int n)
    {
        int rev=0;
        while(n>0)
            {
                int digit=n%10;
                rev=rev*10+digit;
                n=n/10;
            }
        return rev;
    }
    bool sumOfNumberAndReverse(int num) 
    {
        if(num==0) return true;
        bool possible=false;
        for(int i=1;i<num;i++)
            {
                if(i+findreverse(i)==num)
                {
                    possible=true;
                    break;
                }
            }
        return possible;
    }
};
