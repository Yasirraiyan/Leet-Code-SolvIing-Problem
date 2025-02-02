class Solution {
public:
    int countEven(int num) {
        
        int digit;
        int count=0;
        for(int i=1;i<=num;i++)
        {
            int current=i;
            int sum=0;

            while(current>0)
            {
                 digit=current%10;
                 sum+=digit;
                 current=current/10;

            }
             if(sum%2==0)
        {
            count++;
        }
           
        }
       
    return count;
    }
};
