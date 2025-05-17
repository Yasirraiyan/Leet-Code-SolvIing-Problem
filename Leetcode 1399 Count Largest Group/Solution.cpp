#include<vector>
#include<iostream>
using namespace std;
class Solution
 {
public:
  int CalculateDigitSum(int x)
  {
    int sum=0;
    while(x>0)
    {
        int rem=x%10;
        sum+=rem;
        x=x/10;
    }
   return sum;
  }
   bool check(int a,int b)
   {
       bool isequal=false;
       if(CalculateDigitSum(a)==CalculateDigitSum(b))
       {
        isequal=true;
       }
       return isequal;
   }
   int findmax(vector<int> &arr)
   {
    int max=arr[0];
    for(int j=1;j<arr.size();j++)
    {
        if(arr[j]>max)
        {
            max=arr[j];
        }
    }
    return max;
   }
   
       int countLargestGroup(int n)
       {
             int count=0;
             unordered_map<int,int>freq;
             for(int i=1;i<=n;i++)
             {
               
               int sum=CalculateDigitSum(i);
               freq[sum]++;
             }
             vector<int>reserve;
                 int maxSize = 0;
        for (auto& it : freq) 
        {
            maxSize = max(maxSize, it.second);
        }

             for(auto it:freq)
             {
                reserve.push_back(it.second);
             }
             
              if (reserve.size() == 0) return 0;
             for(int k=0;k<reserve.size();k++)
             {
                if(reserve[k]==maxSize)
                {
                    count++;
                }
             }
   return count;
       }
    
};
