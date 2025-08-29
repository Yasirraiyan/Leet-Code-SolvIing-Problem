class Solution
 {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
       int count=0;
       for(int i=0;i< flowerbed.size();i++)
       {
        if(flowerbed[i]==0)
        {
            count++;
        }
       }
       if(n==1&&flowerbed.size()==1&&flowerbed[0]==0) return true;
       if(count<n) return false;
       if(count>n)
       {
           for(int i=0;i< flowerbed.size();i++)
       {
       if(flowerbed[i]==0&&(i==0||flowerbed[i-1]==0)&&(i==flowerbed.size()-1||flowerbed[i+1]==0))
        {
            flowerbed[i]=1;
            n--;
             if(n==0) return true;
        }
       }
       } 
     return n<=0;
    }
};
