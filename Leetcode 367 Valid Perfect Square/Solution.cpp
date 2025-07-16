class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        long long low=0;
        long long  high=num;
       long long mid;
        bool isperfect=false;
        if(num==0) return 0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(mid*mid==num)
            {
             isperfect=true;
             break;
            }
          else  if(mid*mid>num)
            {
             high=mid-1;
            }
            else
            {
            low=mid+1;
            }
        }
        return isperfect;
    }
};
