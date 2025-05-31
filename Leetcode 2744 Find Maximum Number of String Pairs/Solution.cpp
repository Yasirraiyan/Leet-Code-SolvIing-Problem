class Solution 
{
public:
 bool CanMakePair(string a,string b)
 {
  string ans="";
  bool can=false;
  for(int i=b.size()-1;i>=0;i--)
  {
    ans+=b[i];
  }
  if(ans==a)
  {
    can=true;
  }
  return can;
 }
    int maximumNumberOfStringPairs(vector<string>& words) 
{
        int count=0;
        for(int j=0;j<words.size();j++)
        {
        for(int k=j+1;k<words.size();k++)
          {
            if(CanMakePair(words[j],words[k]))
            {

            
            count++;
            }
          }
        }
        return count;
    }
};
