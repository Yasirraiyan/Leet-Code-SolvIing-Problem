#include<vector>
#include<iostream>
#include<cctype>
#include<string>
using namespace std;
class Solution 
{
public:
    string greatestLetter(string s) 
    {
       unordered_set<char>set1;
       string ans="";
       vector<char>reserve;
       for(int i=0;i<s.size();i++)
       {
        set1.insert(s[i]);
       }
       for(int j=0;j<s.size();j++)
       { 
        char lower = tolower(s[j]);
            char upper = toupper(s[j]);
        //if(set1.find(tolower(s[j]))!=set1.end()&&set1.find(toupper(s[j]))!=set1.end())
       if(set1.find(lower)!=set1.end()&&set1.find(upper)!=set1.end())
        {
            reserve.push_back(upper);
        }
       }
        if (reserve.empty()) 
        {
            return "";
        }
       string result="";
       char max=reserve[0];
       for(int k=1;k<reserve.size();k++)
       {
        if(reserve[k]>max)
        {
          max=reserve[k];
        }
       }
       result+=max;
       return result;
    }
};
