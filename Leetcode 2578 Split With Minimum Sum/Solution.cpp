#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
class Solution 
{
public:
    int splitNum(int num) 
    {
        vector<int>ans;
        vector<int>reserve1;
        vector<int>reserve2;
        int sum1=0;
        int sum2=0;
     //   int result;
        while(num>0)
        {
          int rem=num%10;
          ans.push_back(rem);
          num=num/10;
        }
          sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++)
        {
          //if(ans[i]%2==0)
          if(i%2==0)
          {
            reserve1.push_back(ans[i]);
          }
           // if(ans[i]%2!=0)
           if(i%2!=0)
          {
            reserve2.push_back(ans[i]);
          }
        }
       //   sort(reserve1.begin(),reserve1.end());
         // sort(reserve2.begin(),reserve2.end());
          for(int j=0;j<reserve1.size();j++)
          {
            
            sum1+=reserve1[j]*pow(10,reserve1.size()-j-1);
          }
            for(int k=0;k<reserve2.size();k++)
          {
            
            sum2+=reserve2[k]*pow(10,reserve2.size()-k-1);
          }
          int result=sum1+sum2;
          
        
        return result;
    }
};
