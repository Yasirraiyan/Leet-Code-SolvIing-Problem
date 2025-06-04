class Solution 
{
public:
 bool CheckGood(string a)
 {
  unordered_map<char,int>freq;
  bool check=false;
  for(int i=0;i<a.size();i++)
  {
    freq[a[i]]++;
  }
  for(auto it:freq)
  {
    if(it.second>1)
    {
     return false;
      
    }
  }
  return true;
 }
    int countGoodSubstrings(string s) 
    {
        int count=0;
        vector<string>reserve;
        for(int i=0;i<s.size();i++)
        {
          for(int j=1;j<=s.size()-i;j++)
          {

          
        
            reserve.push_back(s.substr(i,j));
          }
          }
        
        vector<string>choice;
        for(int k=0;k<reserve.size();k++)
        {
          if(reserve[k].size()==3)
          {
            choice.push_back(reserve[k]);
          }
        }
        for(int j=0;j<choice.size();j++)
        {
          if(CheckGood(choice[j]))
          {
            count++;
          }
        }
        return count;
    }
};
