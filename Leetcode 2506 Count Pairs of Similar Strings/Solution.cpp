class Solution 
{
public:
  bool CheckSimilar(string a,string b)
  {

    unordered_set<char>set1;
    unordered_set<char>set2;
    bool check=true;
    for(int i=0;i<a.size();i++)
    {
      set1.insert(a[i]);
    }
    for(int j=0;j<b.size();j++)
    {
      if(set1.find(b[j])==set1.end())
      {
        check=false;
      }
    }
    for(int k=0;k<b.size();k++)
    {
      set2.insert(b[k]);
    }
     for(int j=0;j<a.size();j++)
    {
      if(set2.find(a[j])==set2.end())
      {
        check=false;
      }
    }
    return check;
  }
    int similarPairs(vector<string>& words) 
    {
        int count=0;
        for(int k=0;k<words.size();k++)
        {
          for(int m=k+1;m<=words.size()-1;m++)
          {
            if(m!=k)
            {
              if(CheckSimilar(words[k],words[m]))
              {
                count++;
              }
            }
          }
        }
        return count;
    }
};
