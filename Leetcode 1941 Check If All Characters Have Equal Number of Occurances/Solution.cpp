#include<string>
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
class Solution 
{
public:
    bool areOccurrencesEqual(string s) 
    {
        unordered_map<char,int>freq;
        bool isequal=true;
        for(int i=0;i<s.size();i++)
        {
          freq[s[i]]++;
        }
        vector<int>frequency;
         for(auto it : freq)
        {
            frequency.push_back(it.second);
        }
        int ref=frequency[0];

        for(int j=1;j<frequency.size();j++)
        {
       
            
               if(frequency[j]!=ref)
              {
                isequal=false;
                break;
              }
              
             
          
         
          }
        
        return isequal;
    }
};
