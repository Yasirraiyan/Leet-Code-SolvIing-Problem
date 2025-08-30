class Solution
 {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
     {
        vector<int>v;
        for(int i=0;i<numOnes;i++)
        {
            v.push_back(1);
        }
         for(int i=0;i<numZeros;i++)
         {
            v.push_back(0);
         }
         for(int i=0;i<numNegOnes;i++)
        {
            v.push_back(-1);
        }
        //if(numOnes==0) return 0;
       int count=0;
       int sum=0;
       int i=0;
       while(count<=k&&i<k&&i<v.size())
       {
         sum+=v[i];
         i++;
         count++;
       }
       return sum;

    }
};
