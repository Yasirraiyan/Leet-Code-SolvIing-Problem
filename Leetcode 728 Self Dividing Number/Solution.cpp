class Solution {
public:
bool selfdividing(int num)
        {
            bool selfdividing=false;
             int originalNum = num;
             int rem;
            while(originalNum>0)
            {
               rem=originalNum%10;
               if (rem == 0 || num % rem != 0) {
                return false;
            }
               if(num%rem==0)
               {
                    selfdividing=true;
               }
               originalNum=originalNum/10;
            }
            return selfdividing;
        }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
      
            for(int i=left;i<=right;i++)
            {
               if( selfdividing(i))
               {
                ans.push_back(i);
               }
            }
             return ans;
        }
};
    
