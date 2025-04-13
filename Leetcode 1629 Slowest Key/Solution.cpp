#include<vector>
#include<string>
#include<cctype>
#include<iostream>
using namespace std;
class Solution 
{
public:
  int findmax(vector<int>&arr)
  {
    int max=arr[0];
    for(int m=1;m<arr.size();m++)
    {
      if(arr[m]>max)
      {
        max=arr[m];
      }
    }
    return max;
  }
    char slowestKey(vector<int>& releaseTimes, string keysPressed) 
    {
        vector<int>reserve;
        int ans;
        char maxKey='\0';
        vector<int>result;
        for(int i=0;i<releaseTimes.size();i++)
        {
          if(i==0)
          {
            reserve.push_back(releaseTimes[0]);
          }
          if(i>0)
          {
          reserve.push_back(releaseTimes[i]-releaseTimes[i-1]);
          }
        }
        /*for(int j=0;j<reserve.size();j++)
        {
          
             if(findmax(reserve))
             {
                result.push_back(reserve[j]);
             }
          
        }
        */
        int maxtime=findmax(reserve);
       
          for(int m=0;m<reserve.size();m++)
          {
            if(reserve[m]==maxtime)
            {
              //ans=m;     
               maxKey = max(maxKey, keysPressed[m]);       
              }
          }
          
       /* for(int k=0;k<keysPressed.size();k++)
        {
          if(k==ans)
          {
             resultt = max(resultt, keysPressed[k]); // Take lexicographically larger key if there are ties
            resultt+=keysPressed[k];
          }
        }
        */
       char resultt='\0';
        resultt+=maxKey;
        return resultt;
    }
};
