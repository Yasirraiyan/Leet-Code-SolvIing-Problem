class Solution 
{
public:
   int firstUniqChar(string s)
   {
     unordered_map<char,int>freq;
  
     int ans=-1;
     for(int i=0;i<s.size();i++)
     {
        freq[s[i]]++;
     
     }
    
    for(int j=0;j<s.size();j++)
    {
        if(freq[s[j]]==1)
        {
           ans=j;
           break;
        }
    }
    return ans;
   }
    
};
