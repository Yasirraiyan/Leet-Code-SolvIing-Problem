class Solution 
{
public:
 bool CheckConsistent(string a,string b)
 {
  bool check=true;
  unordered_set<char>set1;
  for(int i=0;i<a.size();i++)
  {
    set1.insert(a[i]);
  }
  for(int j=0;j<b.size();j++)
  {
    if(set1.find(b[j])==set1.end())
    {
      check=false;
      break;
    }
  }
  return check;
 }

  
    int countConsistentStrings(string allowed, vector<string>& words) {
       int count=0;
       for(int k=0;k<words.size();k++)
       {
        if(CheckConsistent(allowed,words[k]))
        {
          count++;
        }
       }
       return count;
    }
};
