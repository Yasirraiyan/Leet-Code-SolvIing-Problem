Amar 1 ta integer ase jar nam num.Ei number er kotogula digit dia number divisible hoy oitar man return korbo.
  So, first e 1 ta variable nei jar nam count ja initial 0.
1 ta while loop chalai jekhane condition num>0. 1 ta variable nei digit .karon digit dia vag kore test korbo.
int digit=num%10;
check kori condition je number digit dia divisible kina.
  if(num%digit==0)
  true hoile count++ kori.
  return kori count.
  while(num>0)
        {
            int digit=num%10;
            if(originalNum%digit==0)
            {
                count++;
            }
            num=num/10;
        }

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
  
