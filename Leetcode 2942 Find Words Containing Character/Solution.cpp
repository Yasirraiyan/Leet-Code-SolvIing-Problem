class Solution 
{
public:
bool contain(string a, char b)
{
  bool contain=false;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]==b)
    {
      contain=true;
    }
  }
  return contain;

}
    vector<int> findWordsContaining(vector<string>& words, char x)
     {
        vector<int>ans;
        for(int i=0;i<words.size();i++)
        {
          if(contain(words[i],x))
          {
            ans.push_back(i);
          }
        }
        return ans;
    }
};
