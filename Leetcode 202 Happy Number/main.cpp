class Solution {
public:
    bool isHappy(int n) 
    {
    int sum=0;{
        while(n!=1)
        {
            int a=n%10;
            int b=n/10;
            sum+=a*a+b*b;
        }
        sum=n;
        if(sum==1)
        {
            return true;
        }
        else
        return false;
    }
    }
};
