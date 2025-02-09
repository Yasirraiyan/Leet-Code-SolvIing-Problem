class Solution {
public:
    int countDigits(int num) {
        int count=0;
        int originalNum = num;
        
        while(num>0)
        {
            int digit=num%10;
            if(originalNum%digit==0)
            {
                count++;
            }
            num=num/10;
        }
        return count;
    }
};
