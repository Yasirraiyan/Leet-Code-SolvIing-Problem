class Solution 
{
public:
  bool findvowel(string s)
  {
    bool find=false;
    for(int i=0;i<s.size();i++)
    {
     if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') &&
    (s[s.size() - 1] == 'a' || s[s.size() - 1] == 'e' || s[s.size() - 1] == 'i' || s[s.size() - 1] == 'o' || s[s.size() - 1] == 'u'))
     find=true;
    }
     return find;
    }
   // return find;

  
   
    int vowelStrings(vector<string>& words, int left, int right) 
    {
        int count=0;
        for(int j=left;j<=right;j++)
        {
          if(findvowel(words[j]))
          {
            count++;
          }
        }
        return count;
     
    }
};
