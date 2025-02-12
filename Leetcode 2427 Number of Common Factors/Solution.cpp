class Solution {
public:
    int commonFactors(int a, int b) {
        vector<int> arr1={};
          vector<int> arr2={};
          int count=0;
        for(int i=1;i<=a;i++)
        {
            
            if(a%i==0)
            {
                arr1.push_back(i);

            }
        }
        for(int j=1;j<=b;j++)
        {
            
            if(b%j==0)
            {
                arr2.push_back(j);

            }
        }
        for(int k=0;k<arr1.size();k++)
        {
            for(int m=0;m<arr2.size();m++)
            {
                if(arr1[k]==arr2[m])
                {
                    count++;
                }

            }
        }
        return count;
    }
};
